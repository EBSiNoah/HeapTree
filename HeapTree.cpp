#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> randomVec()
{
	vector<int> output;
	int ranum=rand()%100;
	int idx=0;
	
	while(idx<ranum)
	{
		output.push_back(rand()%100);
		idx++;
	}
	
	return output;
}

void printHeapTree(vector<int> input)
{
	int idx=0;
	int cnt=0;
	int layer=1;
	
	while(idx<input.size())
	{
		cout<<input[idx]<<" | ";
		cnt++;
		if(cnt >= layer)
		{
			cout<<endl;
			cnt=0;
			layer*=2;
		}
		idx++;
	}
}

void printList(vector<int> input)
{
	int idx=0;
	cout<<"Start : "<<endl;
	while(idx<input.size())
	{
		cout<<input[idx]<<" | ";
		idx++;
	}
	cout<<endl;
}

vector<int> heapTreeMin(vector<int> input_vec)
{
	vector<int> HTvec;
	int idx=1;
	int layer=0;
	int parent_idx=0;
	int store=0;
	int cnt=0;
	
	HTvec.push_back(input_vec[0]);
	
	while(idx<input_vec.size())
	{
		HTvec.push_back(input_vec[idx]);
		cnt=idx;
		parent_idx=(cnt-1)/2;
		
		//cout<<"\n input : "<<input_vec[idx]<<endl;
		
		while(HTvec[parent_idx]>HTvec[cnt] && parent_idx>=0)
		{
			//cout<<"swap front : "<<HTvec[parent_idx]<<", parent_idx : "<<parent_idx<<endl;
			//cout<<"swap back : "<<HTvec[idx]<<", cnt : "<<cnt<<endl;
			store=HTvec[parent_idx];
			HTvec[parent_idx]=HTvec[cnt];
			HTvec[cnt]=store;			
			cnt=parent_idx;
			parent_idx=(cnt-1)/2;			
		}
		//printHeapTree(HTvec);
		idx++;
	}
	
	return HTvec;
}

vector<int> heapTreeMax(vector<int> input_vec)
{
	vector<int> HTvec;
	int idx=1;
	int layer=0;
	int parent_idx=0;
	int store=0;
	int cnt=0;
	
	HTvec.push_back(input_vec[0]);
	
	while(idx<input_vec.size())
	{
		HTvec.push_back(input_vec[idx]);
		cnt=idx;
		parent_idx=(cnt-1)/2;
		
		//cout<<"\n input : "<<input_vec[idx]<<endl;
		
		while(HTvec[parent_idx]<HTvec[cnt] && parent_idx>=0)
		{
			//cout<<"swap front : "<<HTvec[parent_idx]<<", parent_idx : "<<parent_idx<<endl;
			//cout<<"swap back : "<<HTvec[idx]<<", cnt : "<<cnt<<endl;
			store=HTvec[parent_idx];
			HTvec[parent_idx]=HTvec[cnt];
			HTvec[cnt]=store;			
			cnt=parent_idx;
			parent_idx=(cnt-1)/2;			
		}
		//printHeapTree(HTvec);
		idx++;
	}
	
	return HTvec;
}

vector<int> deleteHeapTreeMinRoot(vector<int> input_vec)
{
	input_vec[0]=input_vec[input_vec.size()-1];
	input_vec.pop_back();
	
	int idx=0;
	int child_idx=idx*2+1;
	int compare_idx=0;
	int store=0;
	
	while(child_idx<input_vec.size()&&child_idx<idx*2+3)
	{
		if(child_idx+1<input_vec.size() && input_vec[child_idx]>input_vec[child_idx+1])
		{
			compare_idx = child_idx+1;
		}
		else
		{
			compare_idx=child_idx;
		}
		
		if(input_vec[compare_idx]<input_vec[idx])
		{
			store=input_vec[compare_idx];
			input_vec[compare_idx]=input_vec[idx];
			input_vec[idx]=store;
			idx=compare_idx;
			compare_idx=idx*2+1;
			child_idx=compare_idx;
		}
		else
		{
			child_idx+=2;
		}
	}
	
	return input_vec;
}

vector<int> deleteHeapTreeMaxRoot(vector<int> input_vec)
{
	input_vec[0]=input_vec[input_vec.size()-1];
	input_vec.pop_back();
	
	int idx=0;
	int child_idx=idx*2+1;
	int compare_idx=0;
	int store=0;
	
	while(child_idx<input_vec.size()&&child_idx<idx*2+3)
	{
		if(child_idx+1<input_vec.size() && input_vec[child_idx]<input_vec[child_idx+1])
		{
			compare_idx = child_idx+1;
		}
		else
		{
			compare_idx=child_idx;
		}
		
		if(input_vec[compare_idx]>input_vec[idx])
		{
			store=input_vec[compare_idx];
			input_vec[compare_idx]=input_vec[idx];
			input_vec[idx]=store;
			idx=compare_idx;
			compare_idx=idx*2+1;
			child_idx=compare_idx;
		}
		else
		{
			child_idx+=2;
		}
	}
	
	return input_vec;
}

int main()
{
	vector<int> testvec = randomVec();
	vector<int> minheaptest;
	vector<int> maxheaptest;
	vector<int> deletestmin;
	vector<int> deletestmax;
	
	cout<<"Start List : "<<endl;
	printList(testvec);
	
	cout<<endl;
	minheaptest=heapTreeMin(testvec);
	cout<<"Min Heap Tree : "<<endl;	
	printHeapTree(minheaptest);
	cout<<endl;
	
	cout<<endl;
	deletestmin = deleteHeapTreeMinRoot(minheaptest);
	cout<<"Delete Root : "<<endl;
	printHeapTree(deletestmin);
	cout<<endl;
	
	cout<<endl;
	maxheaptest=heapTreeMax(testvec);
	cout<<"Max Heap tree : "<<endl;
	printHeapTree(maxheaptest);
	cout<<endl;
	
	cout<<endl;
	deletestmax = deleteHeapTreeMaxRoot(maxheaptest);
	cout<<"Delete Root : "<<endl;
	printHeapTree(deletestmax);
	cout<<endl;
	
	return 0;
}
