template <typename data_type>
void shellSort( vector<data_type> & vec )
{
	int gap=1;
	int n=vec.size();
	while((gap<<1+1)< (n>>1))
		gap=(gap<<1+1);
	for(;gap>0;gap>>=1)
	{
		for(int i=gap;i<n;i++)
		{
			int temp=std::move(vec[i]);
			int j;
			for(j=i;j>=gap && vec[j-gap]>temp;j-=gap)
				vec[j]=std::move(vec[j-gap]);
			vec[j]=temp;
		}
	}
}

template <typename data_type>
void insertionSort( vector<data_type> & vec )
{
	for(int i=1;i<n;i++)
	{
		int temp=std::move(vec[i]);
		int j;
		for(j=i;j>0 && vec[j-1]>temp;j--)
			vec[j]=std::move(vec[j-1]);
		vec[j]=temp;
	}
}

template<typename data_type>
void countingSort(vector<data_type>&vec)
{
	if(n<=1)
		return;

	int beg=1000000008,end=-1000000008;
	for(int i=0;i<n;i++)
	{
		if(vec[i]<beg)
			beg=vec[i];
		if(vec[i]>end)
			end=vec[i];
	}
	int n=end-beg+1;
	int data[n];
	for(int i=0;i<n;i++)
		data[i]=0;

	for(int i=0;i<vec.size();i++)
		data[vec[i]-beg]++;
	int pos=0;
	for(int i=0;i<n;i++)
	{
		for(int j=data[i];j>0;j--)
		{
			vec[pos++]=i+beg;
		}
	}
}

template<typename data_type>
void radixSort(vector<data_type>&arr)
{
	data_type m=*(max_element(arr.begin(),arr.end()));
	for(data_type div=1 ; m/div ; div*=10)
	{
		vector<data_type>data[10];
		for(int i=0;i<arr.size();i++)
			data[(arr[i]/div)%10].push_back(arr[i]);
		int pos=0;
		for(int i=0;i<10;i++)
		{
			std::copy_n(data[i].begin(),data[i].size(),arr.begin()+pos);
			pos+=data[i].size();
		}
	}
}

void mergeSort(auto begin ,auto end)
{
	if(end-begin>1)
	{
		mergeSort(begin,begin+(end-begin)/2);
		mergeSort(begin+(end-begin)/2 ,end);
		vector<int>arr(end-begin);
		merge(begin ,begin+(end-begin)/2 ,begin+(end-begin)/2  ,end ,arr.begin());
		copy(arr.begin(),arr.end(),begin);
	}
}

void heapify(vector<data_type>&arr, int &n, int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n and arr[i]<arr[l])
		i=l;
	if(r<n and arr[i]<arr[r])
		i=r;
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,i);
	}
}
void heapSort(vector<data_type>&arr)
{
	int n=arr.size();
	for(int i=n/2;i>=0;i--)
	{
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

int partition(vector<data_type>&arr,int low, int high)
{
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<arr[high])
		{
			i++;
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[high],arr[i+1]);
	return i+1;
}
void quickSort(vector<data_type>&arr,int low, int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}