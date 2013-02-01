/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package other.thread;

/**
 *
 * @author PenGuin
 */
public class GoodsDemo {
    public static void main(String[] args) {

        GoodsBufferPool goodsBufferPool = new GoodsBufferPool();

        GoodsProducer goodsProducer = new GoodsProducer(goodsBufferPool);
        GoodsComsumer goodsComsumer = new GoodsComsumer(goodsBufferPool);
        
    }
}
