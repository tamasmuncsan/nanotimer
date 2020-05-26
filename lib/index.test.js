const Nanotimer = require('./index');

describe('nanotimer tests', () => {
  it('getElapsedNs returns elapsed nanoseconds', () => {
    const timer = new Nanotimer();

    timer.start();
    timer.nanosecondDelay(1000000);

    expect(timer.getElapsedNs()).toBeGreaterThan(1000000);
  });

  it('getElapsedUs returns elapsed microseconds', () => {
    const timer = new Nanotimer();

    timer.start();
    timer.microsecondDelay(1000);

    expect(timer.getElapsedUs()).toBeGreaterThan(1000);
  });

  it('getElapsedMs returns elapsed milliseconds', () => {
    const timer = new Nanotimer();

    timer.start();
    timer.millisecondDelay(1);

    expect(timer.getElapsedMs()).toBeGreaterThan(1);
  });

  it('start restarts timer if called twice', () => {
    const timer = new Nanotimer();

    timer.start();
    timer.millisecondDelay(2);
    timer.start();
    timer.millisecondDelay(1);

    const elapsedMs = timer.getElapsedMs();
    expect(elapsedMs).toBeGreaterThan(1);
    expect(elapsedMs).toBeLessThan(2);
  });
});
