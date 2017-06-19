 Primes
A number is prime if it is only divisible by 1 and itself. So for example 2, 3, 5, 79, 311 and 1931 are all prime, while 21 is 
not prime because it is divisible by 3 and 7. To find if a number n is prime we could simply check if it divides any numbers 
below it. We can use the modulus (%) operator to check for divisibility:

for (int i=2; i<n; i++)
   if (n%i==0) return false;

return true;

We can make this code run faster by noticing that we only need to check divisibility for values of i that are less or equal to 
\the square root of n (call this m). If n divides a number that is greater than m then the result of that division will be some 
number less than m and thus n will also divide a number less or equal to m. Another optimization is to realize that there are no
even primes greater than 2. Once we’ve checked that n is not even we can safely increment the value of i by 2. We can now write 
the final method for checking whether a number is prime:

public boolean isPrime (int n)
{
   if (n<=1) return false;
   if (n==2) return true;
   if (n%2==0) return false;
   int m=Math.sqrt(n);

   for (int i=3; i<=m; i+=2)
      if (n%i==0)
         return false;

   return true;
}

Now suppose we wanted to find all the primes from 1 to 100000, then we would have to call the above method 100000 times. 
This would be very inefficient since we would be repeating the same calculations over and over again. 
In this situation it is best to use a method known as the Sieve of Eratosthenes. The Sieve of Eratosthenes will generate all 
the primes from 2 to a given number n. It begins by assuming that all numbers are prime. It then takes the first prime number 
and removes all of its multiples. It then applies the same method to the next prime number. This is continued until all numbers 
have been processed. For example, consider finding primes in the range 2 to 20. We begin by writing all the numbers down:

2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

2 is the first prime. We now cross out all of its multiples, ie every second number:

2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

The next non-crossed out number is 3 and thus it is the second prime. We now cross out all the multiples of 3, ie every third 
number from 3:

2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

All the remaining numbers are prime and we can safely terminate the algorithm. Below is the code for the sieve:

public boolean[] sieve(int n)
{
   boolean[] prime=new boolean[n+1];
   Arrays.fill(prime,true);
   prime[0]=false;
   prime[1]=false;
   int m=Math.sqrt(n);

   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=false;

   return prime;
} 

In the above method, we create a boolean array prime which stores the primality of each number less of equal than n. 
If prime[i] is true then number i is prime. The outer loop finds the next prime while the inner loop removes all the multiples 
of the current prime.
