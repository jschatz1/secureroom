// index.js
const secureRoomAddon = require('bindings')('secure_room');

module.exports = {
  secureRoom: secureRoomAddon.secureRoom
};
