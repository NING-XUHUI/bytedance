/**
 *              牛顿迭代法
 *
 */ 

class Solution{
    int s;
    public int mySqrt(int x){
        s=x;
        if(x==0)return 0;
        else return ((int)(sqrt(x)));
    }
    public double sqrt(double x){
        double res = (x+s/x)/2;
        if(res==x){
            return x;
        }else{
            return sqrt(res);
        }
    }
}
