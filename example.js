const Nanotimer = require('./lib/index');

const timer = new Nanotimer();

console.time('ms delay');
timer.millisecondDelay(100);
console.timeEnd('ms delay');

console.time('us delay');
timer.microsecondDelay(10000);
console.timeEnd('us delay');

console.time('ns delay');
timer.nanosecondDelay(500000);
console.timeEnd('ns delay');

timer.start();
timer.millisecondDelay(100);
console.log(`ms delay (timer): ${timer.getElapsedMs()}`);

timer.start();
timer.microsecondDelay(10000);
console.log(`us delay (timer): ${timer.getElapsedUs()}`);

timer.start();
timer.nanosecondDelay(500000);
console.log(`ns delay (timer): ${timer.getElapsedNs()}`);
