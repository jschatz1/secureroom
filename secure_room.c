#include <node_api.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

/* A sample list of ~1000 words. You can extend this list as needed. */
static const char* words[] = {
  "a",  "ability",  "able",  "about",  "above",  "accept",  "according",  "account",  "across",  "act",  "action",  "activity",  "actually",  "add",  "address",  "administration",  "admit",  "adult",  "affect",  "after",  "again",  "against",  "age",  "agency",  "agent",  "ago",  "agree",  "agreement",  "ahead",  "air",  "all",  "allow",  "almost",  "alone",  "along",  "already",  "also",  "although",  "always",  "american",  "among",  "amount",  "analysis",  "and",  "animal",  "another",  "answer",  "any",  "anyone",  "anything",  "appear",  "apply",  "approach",  "area",  "argue",  "arm",  "around",  "arrive",  "art",  "article",  "artist",  "as",  "ask",  "assume",  "at",  "attention",  "attorney",  "audience",  "author",  "authority",  "available",  "avoid",  "away",  "baby",  "back",  "bad",  "bag",  "ball",  "bank",  "bar",  "base",  "be",  "beat",  "beautiful",  "because",  "become",  "bed",  "before",  "begin",  "behavior",  "behind",  "believe",  "benefit",  "best",  "better",  "between",  "beyond",  "big",  "bill",  "billion",  "bit",  "black",  "blood",  "blue",  "board",  "body",  "book",  "born",  "both",  "box",  "boy","break","bring","brother","budget","build","building","business","but","buy","by","call","camera","campaign","can","cancer","candidate","capital","car","card","care","career","carry","case","catch","cause","cell","center","central","century","certain","certainly","chair","challenge","chance","change","character","charge","check","child","choice","choose","church","citizen","city","civil","claim","class","clear","clearly","close","coach","cold","collection","college","color","come","commercial","common","community","company","compare","computer","concern","condition","conference","congress","consider","consumer","contain","continue","control","cost","could","country","couple","course","court","cover","create","crime","cultural","culture","cup","current","customer","cut","dark","data","daughter","day","dead","deal","debate","decade","decide","decision","deep","defense","degree","democrat","democratic","describe","design","despite","detail","determine","develop","development","difference","different", "difficult","dinner","direction","director","discover","discuss","discussion","disease","do","doctor","dog","door","down","draw","dream","drive","drop","during","each","early","east","easy","eat","economic","economy","edge","education","effect","effort","eight","either","election","else","employee","end","energy","enjoy","enough","enter","entire","environment","environmental","especially","establish","even","evening","event","ever","every","everybody","everyone","everything","evidence","exactly","example","executive","exist","expect","experience","expert","explain","eye","face","fact","factor","fail","fall","family","far","fast","father","fear","federal","feel","feeling","few","field","figure","fill","film","final","finally","financial","find","fine","finger","finish","fire","firm","first","fish","five","floor","fly","focus","follow","food","foot","for","force","foreign","forget","form","former","forward","four","free","friend","from","front","full","fund","future","game","garden","gas","general","generation","get","girl","give","glass","go","goal","good","government","great","green","ground","group","grow","growth","guess","gun","guy","hair","half","hand","hang","happen","happy","hard","have","he","head","health","hear","heart","heat","heavy","help","her","here","herself","high","him","himself","his","history","hit","hold","home","hope","hospital","hot","hotel","hour","house","how","however","huge","human","hundred","husband","i","idea","identify","if","image","imagine","impact","important","improve","in","include","including","increase","indeed","indicate","individual","industry","information","inside","instead","institution","interest","interesting","international","interview","into","investment","involve","issue","it","item","its","itself","job","join","just","keep","key","kid","kind","kitchen","know","knowledge","land","language","large","last","late","later","laugh","law","lawyer","lay","lead","leader","learn","least","leave","left","leg","legal","less","let","letter","level","lie","life","light","like","likely","line","list","listen","little","live","local","long","look","lose","loss","lot","love","low","machine","magazine","main","maintain","major","majority","make","man","manage","management","manager","many","market","marriage","material","matter","may","maybe","me","mean","measure","media","medical","meet","meeting","member","memory","mention","message","method","middle","might","military","million","mind","minute","miss","mission","model","modern","moment","money","month","more","morning","most","mother","mouth","move","movement","movie","mr","mrs","much","music","must","my","myself","name","nation","national","natural","nature","near","nearly","necessary","need","network","never","new","news","newspaper","next","nice","night","no","none","nor","north","not","note","nothing","notice","now","number","occur","of","off","offer","office","officer","official","often","oh","oil","ok","old","on","once","one","only","onto","open","operation","opportunity","option","or","order","organization","other","others","our","out","outside","over","own","owner","page","pain","painting","paper","parent","part","participant","particular","particularly","partner","party","pass","past","patient","pattern","pay","peace","people","per","perform","performance","perhaps","period","person","personal","phone","physical","pick","picture","piece","place","plan","plant","play","player","pm","point","police","policy","political","politics","poor","popular","population","position","positive","possible","power","practice","prepare","present","president","pressure","pretty","prevent","price","private","probably","problem","process","produce","product","production","professional","professor","program","project","property","protect","prove","provide","public","pull","purpose","push","put","quality","question","quickly","quite","race","radio","raise","range","rate","rather","reach","read","ready","real","reality","realize","really","reason","receive","recent","recently","recognize","record","red","reduce","reflect","region","relate","relationship","religious","remain","remember","remove","report","represent","republican","require","research","resource","respond","response","responsibility","rest","result","return","reveal","rich","right","rise","risk","road","rock","role","room","rule","run","safe","same","save","say","scene","school","science","scientist","score","sea","season","seat","second","section","security","see","seek","seem","sell","send","senior","sense","series","serious","serve","service","set","seven","several","shake","share","she","shoot","short","shot","should","shoulder","show","side","sign","significant","similar","simple","simply","since","sing","single","sister","sit","site","situation","six","size","skill","skin","small","smile","so","social","society","soldier","some","somebody","someone","something","sometimes","son","song","soon","sort","sound","source","south","southern","space","speak","special","specific","speech","spend","sport","spring","staff","stage","stand","standard","star","start","state","statement","station","stay","step","still","stock","stop","store","story","strategy","street","strong","structure","student","study","stuff","style","subject","success","successful","such","suddenly","suffer","suggest","summer","support","sure","surface","system","table","take","talk","task","tax","teach","teacher","team","technology","television","tell","ten","tend","term","test","than","thank","that","the","their","them","themselves","then","theory","there","these","they","thing","think","third","this","those","though","thought","thousand","threat","three","through","throughout","throw","thus","time","to","today","together","tonight","too","top","total","tough","toward","town","trade","traditional","training","travel","treat","treatment","tree","trial","trip","trouble","true","truth","try","turn","tv","two","type","under","understand","unit","until","up","upon","us","use","usually","value","various","very","victim","view","violence","visit","voice","vote","wait","walk","wall","want","watch","water","way","we","weapon","wear","week","weight","well","west","western","what","whatever","when","where","whether","which","while","white","who","whole","whom","whose","why","wide","wife","will","win","wind","window","wish","with","within","without","woman","wonder","word","work","worker","world","worry","would","write","writer","wrong","yard","yeah","year","yes","yet","you","young","your","yourself"
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
