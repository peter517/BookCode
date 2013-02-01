/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package other.thread;

/**
 *
 * @author PenGuin
 */
public class GoodsBufferPool {

    //生产一个，消费者消费一个
    private int goodSerialNum = 0;
    private boolean lock = false;

    public synchronized int getGood() throws InterruptedException {
//        synchronized ("Goods") {}
        if (!lock) {
            wait();
        }

        lock = false;
        System.out.println("Get：" + goodSerialNum);

        notify();

        return goodSerialNum;

    }

    public synchronized void putGood(int goodSerialNum) throws InterruptedException {
//        synchronized ("Goods") {}
        if (lock) {
            wait();
        }

        this.goodSerialNum = goodSerialNum;
        System.out.println("Put：" + goodSerialNum);
        lock = true;

        notify();

    }
}
