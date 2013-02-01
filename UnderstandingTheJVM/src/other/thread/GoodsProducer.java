/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package other.thread;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author PenGuin
 */
public class GoodsProducer implements Runnable {

    private GoodsBufferPool goodsBufferPool;
    private int goodSerialNum = 0;

    public GoodsProducer(GoodsBufferPool goodsBufferPool) {
        this.goodsBufferPool = goodsBufferPool;
        new Thread(this, "Producer").start();
    }

    public void run() {
        while (true) {
            try {
                goodsBufferPool.putGood(goodSerialNum++);
            } catch (InterruptedException ex) {
                Logger.getLogger(GoodsProducer.class.getName()).log(Level.SEVERE, null, ex);
            }
            try {
                Thread.sleep(0);
            } catch (InterruptedException ex) {
                Logger.getLogger(GoodsProducer.class.getName()).log(Level.SEVERE, null, ex);
            }

        }

    }
}
