import java.util.*;

import java.math.*;

class Main {

 



public static void main(String[] args) {

 

Scanner in=new Scanner(System.in);

int ii=in.nextInt();

while(ii>0)

{

BigInteger a=in.nextBigInteger();

BigInteger x, y;

x=a.divide(new BigInteger("2"));

y=new BigInteger("1");

while(y.compareTo(x)!=0)

{

x=y;

y=x.add((a.divide(x)));

y=y.divide(new BigInteger("2"));

}



System.out.println(y);

ii--;

}
}
}

