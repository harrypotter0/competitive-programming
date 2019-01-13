vector< bool >isp(n8, 1);
vector< long >prime;
vector< long >product;
void pre()
{
    for(int i=2; i<=n8; i++)
    {
        if(isp[i])
        {
            prime.push_back(i);
            product.push_back(1LL*i*i*i);
            if(i < 10001)
            for(int j=i*i; j<=n8-2; j+=i)
            {
                isp[j] = 0;
            }
        }
    }
}
