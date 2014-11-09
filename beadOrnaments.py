#I'm not gonna lie, I had to google this one
#as it took me a while to even understand what
#the question was asking for. I initially thought
#the ornament would be like a necklace and it took
#me a while to realize that the beads can be arranged
#as a tree, even though it explicitly said to think of it as a tree.
#Yeah, I ended up just implementing the code from the blog solution.
#I also tried to do it in C++, but I was failing half of the test
#cases most likely due to overflow errors.

import math

t = int(input())
for i in range(t):
    ans=1
    sumb=0
    n = int(input())
    str1 = raw_input()
    for b in str1.split():
        b=int(b)
        sumb+=b
        ans*=b**(b-1)
        ans = ans % 1000000007


    ans*=sumb**(n-2)
    ans = ans % 1000000007
    print int(ans)
