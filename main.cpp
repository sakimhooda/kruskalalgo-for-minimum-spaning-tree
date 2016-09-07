#include <iostream>

using namespace std;

void kruskal(int e[][3],int node,int edge){
int visit[edge],sets[node],c=0,sum=0,E[node-1][2];
//intilisation
for(int i=0;i<node;i++){
    sets[i]=i;
    visit[i]=1;

}
for(int i=node;i<edge;i++){
        visit[i]=1;

}
int temp,k,m=0;
while(c<node){
	temp=9999;k=-1;
    for(int i=0;i<edge;i++){
        if(temp>e[i][2] && visit[i]==1){
            temp=e[i][2];
            k=i;
        }
    }

    if(k!=-1){
        visit[k]=0;
        int t1=e[k][0] ,t2=e[k][1] ;
        if(sets[e[k][0] ]!=sets[e[k][1]]){
        	E[c][0]=t1+1;
        	E[c][1]=t2+1;
            c++;
            m--;
            sum+=e[k][2];
            t1=sets[e[k][0]]; t2=sets[e[k][1]];

         for(int i=0;i<node;i++){
            if(sets[i]==t1 ||sets[i]==t2)
                {sets[i]=m;
                //cout<<i+1<<" ";
                }
         }
           //cout<<"\t"<<sum<<endl<<endl;



        }
        else{
            visit[k]=0;
        }
    }
    else
      break;

}
cout<<"wight of minimum spaning tree is   : "<<sum<<endl
<<"the order of edge selection will be"<<endl;
for(int i=0;i<node-1;i++){
	cout<<E[i][0]<<"  "<<E[i][1]<<endl;
}







}



int main()
{
    int node,edge;
    cout<<"enter the no of nodes and edge repectively\n";
    cin>>node>>edge;
    int e[edge][3],t1,t2;
    cout<<"enter the no of edge start end and weight\n";
    for(int i=0;i<edge;i++){
        cin>>t1>>t2>>e[i][2];
        e[i][0]=t1-1;
        e[i][1]=t2-1;
    }

    kruskal(e,node,edge);


    return 0;
}
