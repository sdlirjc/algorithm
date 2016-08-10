class URL{
public:
    string md5;
    string domain;
    string path;//domain+path==valid url
    bool isBlack;
};

class BlackList{
private:
    set<URL>list;
public:
    void add(URL entry){
        list.push(entry);
    }
    void clear(){
        list.clear();
    }
    int size(){
        return list.size();
    }
    bool find(URL entry){
        return list.contains(entry);
    }
}

//*.fakegoogle.com
//www.fakeyahoo.com
//mail.fakeyahoo.com
//host1.mail.fakeyahoo.com
//http://www.facebook.com/chris.grier


stirng removePrefix(stirng input){
    if(input.startWith("https://")) return input.substr(8);
    if(input.startWith("http://")) return input.substr(7);
    return input;
}
stirng removeSuffix(stirng input){
    // remove /chris...
}

bl1 = "host1.mail.fakeyahoo.com" = ["host1", "mail", "fakeyahoo", "com"]
check1 = "host1.www.fakeyahoo.com"
check2 = "another.host1.www.fakeyahoo.com"
check3 = "chris.grier.in"

bl1.endWith(topmain)

vector<string>checkArray=split(check,".");
vector<string>blArray=split(bl,".");
bool headSame=true;
bool tailSame=true;
for(int i=0;i<checkArray.size()&&i<blArray.size();i++){
    if(checkArray[i]!=blArray[i]){
        headSame=false;
        break;
    }
}
//i ==1 bl1[1]=mail


//bl = ["host1", "mail", "fakeyahoo", "com"]
//check = ["host1", "www", "fakeyahoo", "com"]
for(int i=check.size()-1,int j=bl.size()-1;i>=0,j>=0;i--,j--){
    if(checkArray[i]!=blArray[j]){
        tailSame=false;
        break;
    }
}
//




match(bl1, check1) == false

//top domains:

//com, org, edu
facebook.com

//cn,ru,in,
facebook.com.cn

//before top main-> subdomain



if(url.endWith("l"))


bool match(BlackList bl,string url){
    string urls[2];
    urls= breakURL(url);// break url -> header + top domain
    // urls -> [www, facebook.com]//header, topdomain
    string checkString1=url;
    string checkString2='*'+'.'+urls[1];
    if(bl.find(checkString2))return true;
    if(bl.find(checkString1))return true;
    
}

int main(.....){

    vector<URL> bigList;
    BlackList bl ;//contains some bad URL
    for(int i=0;i<bigList.size();i++){
        string pureURL=removePrefix(bigList[i]);
        if(match(bl,pureURL))bigList[i].isBlack=true;
    }


    return 0;
}


int main(.....){

    vector<URL> bigList;
    BlackList bl ;//contains some bad URL
    for(int i=0;i<bigList.size();i++){
        if(bl.find(bigList[i])) bigList[i].isBlack=true;//O(1)
    }
    
    
    //O(N),N=bigList.size()
    return 0;
}
