class Solution {
public:
    long long mo(long long x,long long m)
    {
        return x%m;
    }
    long long countVowelPermutation(int n) {
        long long A[n+1],E[n+1],I[n+1],U[n+1],O[n+1];
        A[0]=1,E[0]=1,I[0]=1,U[0]=1,O[0]=1;

        for(int i=1;i<=n;i++)
        {
            A[i]=mo(U[i-1],1000000007)+mo(E[i-1],1000000007)+mo(I[i-1],1000000007);
            A[i]=mo(A[i],1000000007);
            E[i]=mo(A[i-1],1000000007)+mo(I[i-1],1000000007);
            E[i]=mo(E[i],1000000007);
            I[i]=mo(E[i-1],1000000007)+mo(O[i-1],1000000007);
            I[i]=mo(I[i],1000000007);
            U[i]=mo(I[i-1],1000000007)+mo(O[i-1],1000000007);
            U[i]=mo(U[i],1000000007);
            O[i]=mo(I[i-1],1000000007);
            O[i]=mo(O[i],1000000007);
        }
        return mo(mo(A[n-1],1000000007)+mo(E[n-1],1000000007)+mo(I[n-1],1000000007)+
            mo(U[n-1],1000000007)+mo(O[n-1],1000000007),1000000007);
    }
};