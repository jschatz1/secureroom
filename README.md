# secure-room

A secure room code generator implemented as a Node.js native addon.

## Installation

```bash
npm install secure-room
```

## Usage

```javascript
const { secureRoom } = require('my-secure-room');

console.log(secureRoom()); // Example output: "act-about-5927"
```

## Is this faster?

In theory, yes—a C addon can execute certain computations faster than equivalent JavaScript because it’s compiled to machine code and can leverage lower-level optimizations. However, for a task like generating a secure room code, which involves simple operations and string manipulations, the performance gain is likely to be negligible. In many real-world cases, the overhead of crossing the boundary between JavaScript and native code may offset any raw performance benefits.