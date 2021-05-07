const supa = require('./cmake-build-debug/supa_node_native.node');
console.log(supa);
console.log(supa.main());
console.log(supa.hello());
module.exports = supa;
