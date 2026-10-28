### Job Sequencing Problem :- 
So hamo ek 2d array given hoga, jisme 3 column hoga, 1 column : JobId, 2nd Column : Deadline 3rd Column : Profit. So hamre pass kuchh task hai, inko hamko complete karna hai in tarike se ki jo hamara progit hoga wo maximum hona chahiye. So hamko Deadline bhi diya hua jo bata raha hai ki particular deadline ke ander hamko task ko complete karna hai. Ek baar mai ham ek task he kar sakte hai. 

So ham dealine array le lenge jisko 0 se initialize kar denge which means ki task abhi nahi hua , agar koi task filled hai pahle se then current task ko nahi select kar sakte as uski deadline khatam ho chuki hai. 
Selection is based on the Maximum profit. 

Note kisi bhi task ko karne ke liye 1 unit of time he lag raha hai. 

Jab bhi ham selection kar rahe hai, So ham try karenge ki ham maximum deadline time par  fill kare  so ki agar uske pahle ki deadline ka job mila toh uske kar paye aur apne deadline array mai apne job ko mark  kar paaye.

Note :-  Normal se baat hai agar hamre pass jayda kaam hai, aur sabhki deadline alag hai karne ke liye aur ham chahte ki profit jayda ho, tab sabse jayda profit dena wala kaam pahle select karte hai, agar uski deadline 3 mahine mai kabhi karke de do so han 3 mahine usko karenge kyuki hamko pata koi bhi kaam karne samay 1 mahine se jayda nahi le raha aur uske pahle ke deadline wale aur maximum profit ko le lenge.

Steps :- 
1. Profit ke basis par array ko sort karenge, descending order mai. 
We use important concept kyuki col 2d array mai hai sirf col(Profit) ko sort nahi kar hai, col ke according do(jobId, DeadLine) aur col ko sort kar rahe hai.

Code part :- 
1. sabse pahle see the maximum deadline task , utne size ka ek array bana do , aur isko 0 se  initialize kar do
2. maximum profit ko utha lo, if more than one maximum then choose anyone. 
3. then chhosen , deadline jitna hai utne par jakar apne visit array mai mark one kardo. and so on. 
4. if having the situation, that ki jo maximum profit jiska hai uske deadline ko jab ham check aur dekh rahe then uski position pahle se he mark hai visited array mai then ham us position ke aage wale index chack karenge jaha khali milega waha visited mark 1 kar denge. if no such position find then we cannot aaaogn that job. 


Code Implementation :- 

```

```