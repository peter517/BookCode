package other.security;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.MessageDigest;

import javax.crypto.Cipher;

public class DigitalSignature {

	    public static void main(String[] args) throws Exception {
	        
	        // 检查输入参数，得到明文
	        byte[] plainText = "我是一个加密了的明文，别想知道我的内容！".getBytes("UTF8");
	        
	        // 得到MD5消息摘要对象并且计算明文摘要
	        MessageDigest messageDigest = MessageDigest.getInstance("MD5");
	        System.out.println("" + messageDigest.getProvider().getInfo());
	        
	        messageDigest.update(plainText);
	        byte[] md = messageDigest.digest();
	        System.out.println("Digest: ");
	        System.out.println(new String(md, "UTF8"));
	        
	        // 生成RSA密钥对
	        System.out.println("Start generating RSA key");
	        KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
	        keyGen.initialize(1024);
	        KeyPair key = keyGen.generateKeyPair();
	        System.out.println("Finish generating RSA key");
	        
	        
	        // 得到RSA cipher同时列出算法的提供人
	        Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
	        System.out.println("" + cipher.getProvider().getInfo());
	        
	        // 将信息加密并且利用RSA私钥进行签名
	        System.out.println("Start encryption");
	        cipher.init(Cipher.ENCRYPT_MODE, key.getPrivate());
	        byte[] cipherText = cipher.doFinal(md);
	        System.out.println("Finish encryption: ");
	        System.out.println(new String(cipherText, "UTF8"));
	        
	        
	        
	        
	        // 利用RSA公钥进行解密
	        System.out.println("Start decryption");
	        cipher.init(Cipher.DECRYPT_MODE, key.getPublic());
	        byte[] newMD = cipher.doFinal(cipherText);
	        System.out.println("Finish decryption: ");
	        System.out.println(new String(newMD, "UTF8"));
	        
	        // 重新建立信息明文
	        System.out.println("Start signature verification");
	        messageDigest.reset();
	        messageDigest.update(plainText);
	        byte[] oldMD = messageDigest.digest();
	        // 检查签名前后数据是否相同
	        int len = newMD.length;
	        if (len > oldMD.length) {
	            System.out.println("Signature failed, length error");
	            System.exit(1);
	        }
	        for (int i = 0; i < len; ++i) {
	            if (oldMD[i] != newMD[i]) {
	                System.out.println("Signature failed, element error");
	                System.exit(1);
	            }
	        }
	        System.out.println("Signature verified");
	    }
	}


