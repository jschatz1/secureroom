#include <node_api.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

/* A sample list of words. You can extend this list as needed. */
static const char* words[] = {
  "a", "ability", "able", "about", "above", "accept", "according", "account",
  "across", "act", "action", "activity", "actually", "add", "address", "administration",
  "admit", "adult", "affect", "after", "again", "against", "age", "agency",
  "agent", "ago", "agree", "agreement", "ahead", "air", "all", "allow", "almost",
  "alone", "along", "already", "also", "although", "always", "American", "among",
  "amount", "analysis", "and", "animal", "another", "answer"
};
static const size_t words_count = sizeof(words)/sizeof(words[0]);

/* Return a random word from the list. */
static const char* random_word() {
  size_t index = rand() % words_count;
  return words[index];
}

/* Compute 10^n for n >= 0 */
static int pow10_int(int n) {
  int result = 1;
  while(n-- > 0) {
    result *= 10;
  }
  return result;
}

/* Return a random number with exactly n_digits.
   If n_digits == 1, the number is between 0 and 9.
   Otherwise, it is between 10^(n_digits-1) and (10^(n_digits))-1.
*/
static int random_number(int n_digits) {
  int lower = (n_digits == 1) ? 0 : pow10_int(n_digits - 1);
  int upper = pow10_int(n_digits) - 1;
  return lower + rand() % (upper - lower + 1);
}

/* Generate a secure room code.
   Parameters:
     n_words: number of random words
     n_digits: number of digits in the random number
     join_char: string used to join parts
   Returns a newly allocated string (caller must free it).
*/
static char* secure_room_code(int n_words, int n_digits, const char* join_char) {
  /* Estimate a buffer size. Assume average word length of 10 and join_char length. */
  size_t join_len = strlen(join_char);
  size_t bufsize = n_words * 10 + n_digits + (n_words + 1) * join_len + 1;
  char *result = malloc(bufsize);
  if (!result) return NULL;
  result[0] = '\0';

  for (int i = 0; i < n_words; i++) {
    const char *w = random_word();
    strcat(result, w);
    if (i < n_words - 1) {
      strcat(result, join_char);
    }
  }
  /* Append join_char and the random number */
  strcat(result, join_char);
  int num = random_number(n_digits);
  char numbuf[32];
  snprintf(numbuf, sizeof(numbuf), "%d", num);
  strcat(result, numbuf);

  return result;
}

/* N-API wrapped function.
   Accepts up to three optional arguments:
    - nWords (number, default 2)
    - nDigits (number, default 4)
    - joinChar (string, default "-")
*/
napi_value SecureRoomWrapped(napi_env env, napi_callback_info info) {
  napi_status status;
  size_t argc = 3;
  napi_value args[3];
  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);
  if (status != napi_ok) return NULL;

  int nWords = 2;
  int nDigits = 4;
  char joinChar[16] = "-";

  if (argc >= 1) {
    status = napi_get_value_int32(env, args[0], &nWords);
    if (status != napi_ok) nWords = 2;
  }
  if (argc >= 2) {
    status = napi_get_value_int32(env, args[1], &nDigits);
    if (status != napi_ok) nDigits = 4;
  }
  if (argc >= 3) {
    size_t str_size;
    size_t copied;
    status = napi_get_value_string_utf8(env, args[2], joinChar, sizeof(joinChar), &copied);
    if (status != napi_ok) {
      strcpy(joinChar, "-");
    }
  }

  /* Generate the secure room code */
  char *code = secure_room_code(nWords, nDigits, joinChar);
  if (code == NULL) {
    napi_throw_error(env, NULL, "Memory allocation failed");
    return NULL;
  }
  
  napi_value result;
  status = napi_create_string_utf8(env, code, NAPI_AUTO_LENGTH, &result);
  free(code);
  if (status != napi_ok) return NULL;
  return result;
}

/* Module initialization */
napi_value Init(napi_env env, napi_value exports) {
  srand((unsigned) time(NULL));  // Seed random number generator
  napi_status status;
  napi_value fn;
  status = napi_create_function(env, NULL, 0, SecureRoomWrapped, NULL, &fn);
  if (status != napi_ok) return NULL;
  status = napi_set_named_property(env, exports, "secureRoom", fn);
  if (status != napi_ok) return NULL;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
