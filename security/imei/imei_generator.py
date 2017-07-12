
import random
import math 


def calculate(e):
      

    imei_to_list=[]
    all_odds=[]
    all_evens=[]
    doubled_even=[]
    even_total=0
    odd_total=0
    
    imei_to_list=list(e)
    all_odds=imei_to_list[::2]
    all_evens=imei_to_list[1::2]
        
    for x in all_evens:
        h=int(x)*2
        doubled_even.append(str(h))
    doubled_even="".join(doubled_even)
        
    for x in doubled_even:
        even_total+=int(x)
    all_odds="".join(all_odds)
        
    for x in all_odds:
        odd_total+=int(x)
    add_up=even_total+odd_total
    divide_up=add_up%10
        
    if divide_up==0:
        return e+str(divide_up)
    after_sub=10-divide_up
    return e+str(after_sub)
            

if __name__=="__main__":
    for n in range(1000):
        imei=str(random.randint(1E8, 1E9))
        get_digits=""
        five_digits=""
        full_digits=""         

        for n in range(10):
            get_digits=get_digits+str(n)

        for n in range(5):
            five_digits=five_digits+str(random.choice(get_digits))

        full_digits =   imei+five_digits
        full_str    =   calculate(full_digits)
        print("\""+full_str+"\",")




