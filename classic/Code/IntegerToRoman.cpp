class Solution {
public:
    string intToRoman(int num) {
        string n="";
        char c[7]={'M','D','C','L','X','V','I'};
        int s[7]={1000,500,100,50,10,5,1};
        for(int i=0;i<7;i+=2){
            int d=num/s[i];
            if(d==0)continue;
            if(d<=3){
                n.append(d,c[i]);
            }else if(d==4){
                n.append(1,c[i]);
                n.append(1,c[i-1]);
            }else if (d==5){
                n.append(1,c[i-1]);
            }else if(d<=8){
                n.append(1,c[i-1]);
                n.append(d-5,c[i]);
            }else{
                n.append(1,c[i]);
                n.append(1,c[i-2]);
            }
            num=num%s[i];
        }
        return n;
    }
};
