/*标  题: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 13:05:32 2014, 美东)

given a string ,return the longest substring that contains at most two
characters.

该咋写？
--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 12.]
    
    
    tomatoface
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 2 ]

发信人: tomatoface (TomatoFace), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 13:24:53 2014, 美东)

Two pointer traversal + memorization. 这类题目是不是都差不多这样
--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 131.]
 
    fenghaolw
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 3 ]

发信人: fenghaolw (生如夏花), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 13:24:54 2014, 美东)

和leetcode的Longest Substring Without Repeating Characters类似

两个指针start和end，从左往右扫一遍，如果start和end之间符合条件就++end，否则
就++start

--
※ 修改:·fenghaolw 於 Aug 28 13:25:16 2014 修改本文·[FROM: 68.]
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 68.]
 
    lolhaha
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 4 ]

发信人: lolhaha (长期骑驴,一直找马), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 13:25:10 2014, 美东)

我去替你onsite吧
【 在 czcz (czcz) 的大作中提到: 】
: given a string ,return the longest substring that contains at most two
: characters.
: 该咋写？



--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 72.]
 
    vRussell
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 5 ]

发信人: vRussell (LRG), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 13:37:26 2014, 美东)

我电面的时候问了这题，记录一下那个turning point 就好
--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 135.]
 
    MMMMMMM
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 6 ]

发信人: MMMMMMM (MMMMMM), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 14:49:55 2014, 美东)

类似找longest substring without duplicates. 用queue记录2个已经出现的char，用
unordered_map 记录这2个char最后出现的index。
string findsubstring(string s) {
    if(s.empty()) {
        return string();
    }
    queue<char> que;
    unordered_map<char, int> map;
    int maxlen = 0, maxindex=0, index=0;
    for(int i=0; i<s.size(); ++i) {
        if(map.find(s[i])==map.end()) {
            if(que.size()==2) {
                if(i-index>maxlen) {
                    maxlen = i-index;
                    maxindex = index;
                }
                //update que and map
                char c=que.front();
                que.pop();
                index = map[c]+1;
                map.erase(c);
            }
            map[s[i]] = i;
            que.push(s[i]);
        } else {
            map[s[i]] = i;
        }
    }
    if(s.size()-index>maxlen) {
        maxlen = s.size()-index;
        maxindex = index;
    }
    return s.substr(maxindex, maxlen);
}
--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 50.]
 
    idontknowyou
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 7 ]

发信人: idontknowyou (idontknow), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 14:52:01 2014, 美东)

如果问你一个character你就会，问两个就不会了？是不是第二天就被据了：）
开个玩笑啊 别怒
--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 50.]
 
    jbdrnzd
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 8 ]

发信人: jbdrnzd (bd), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 17:01:14 2014, 美东)

at most two
characters.。什么意思？2个不一样的？aaaaab算longest是么？
--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 107.]
 
    sweetysnower
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 9 ]

发信人: sweetysnower (sweetysnower), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 17:33:21 2014, 美东)

这题啥意思都没看懂，lz题目没写清楚吧？
--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 129.]
 
    achromate
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 10 ]

发信人: achromate ( zephyr), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Thu Aug 28 18:25:21 2014, 美东)

没看懂， string 里除了字符 都是空格？
【 在 czcz (czcz) 的大作中提到: 】
: given a string ,return the longest substring that contains at most two
: characters.
: 该咋写？



--
※ 来源:·WWW 未名空间站 网址：mitbbs.com 移动：在应用商店搜索未名空间·[FROM: 166.]
 
    weibest
进入未名形象秀
    我的博客
    
    
[回复] [回信给作者] [本篇全文] [本讨论区] [修改] [删除] [转寄] [转贴] [收藏] [举报]         [ 11 ]

发信人: weibest (PTMF2013), 信区: JobHunting
标  题: Re: Google onsite 题目求助
发信站: BBS 未名空间站 (Fri Aug 29 02:10:39 2014, 美东)

这个空间复杂度高了，会要求你不用额外数据结构来解决。
这题 corner case多

【 在 MMMMMMM (MMMMMM) 的大作中提到: 】
: 类似找longest substring without duplicates. 用queue记录2个已经出现的char，用
: unordered_map 记录这2个char最后出现的index。
: string findsubstring(string s) {
:     if(s.empty()) {
:         return string();
:     }
:     queue<char> que;
:     unordered_map<char, int> map;
:     int maxlen = 0, maxindex=0, index=0;
:     for(int i=0; i<s.size(); ++i) {
: ...................*/





