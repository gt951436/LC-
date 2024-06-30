class Solution {
    void makeset( vector<int>&parent, vector<int>&rank,int n){
	    for(int i=0;i<=n;i++){
	        parent[i]=i;
	        rank[i]=0;
	    }
	}
	
	int findparent( vector<int>&parent,int node){
	    if(parent[node]==node) return node;
	    return parent[node]=findparent(parent,parent[node]);
	}
	
	void unioinset( vector<int>&parent,int u,int v, vector<int>&rank){
	    u=findparent(parent,u);
	    v=findparent(parent,v);
	    if(rank[u]>rank[v]){
	        parent[v]=u;
	    }
	    else if(rank[u]<rank[v]){
	        parent[u]=v;
	    }
        else{
            parent[v]=u;
            rank[u]++;
        }
	}

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parent1(n+1),rank1(n+1);
        vector<int>parent2(n+1),rank2(n+1);
        int c=0;
        makeset(parent1,rank1,n);
        makeset(parent2,rank2,n);
         // Prioritize type3 edges first
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                if(findparent(parent1,edges[i][1])!=findparent(parent1,edges[i][2])){
                    unioinset(parent1,edges[i][1],edges[i][2],rank1);
                }
                if(findparent(parent2,edges[i][1])!=findparent(parent2,edges[i][2])){
                    unioinset(parent2,edges[i][1],edges[i][2],rank2);
                }
                else c++;
            }
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                if(findparent(parent1,edges[i][1])!=findparent(parent1,edges[i][2])){
                    unioinset(parent1,edges[i][1],edges[i][2],rank1);
                }
                else{
                    c++;
                }
            }
            else if(edges[i][0]==2){
                if(findparent(parent2,edges[i][1])!=findparent(parent2,edges[i][2])){
                    unioinset(parent2,edges[i][1],edges[i][2],rank2);
                }
                else{
                    c++;
                }
            }
        } 
        for(int i=1; i<=n; i++){
            if(findparent(parent1, i) != findparent(parent1, n) || findparent(parent2, i) != findparent(parent2, n)){
                return -1;
            }
        }
        return c;
    }
};