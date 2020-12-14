//程序名称:图的邻接表存储及实现
//编译环境:Dev-C++ 5.5.3
//作者:杨建文
//最后修改:2020-12-13

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

typedef int Vertex;         /*用顶点下标表示顶点,为整型*/
typedef int WeightType;
typedef char DataType;
*顶点存储的数据类型设为字符型
*边的定义*/
typedef struct ENode *PtrToENode;struct ENode{
Vertex V1,v2;*有向边<V1,V2> */weightType weight;/*权重*/
;
typedef PtrToENode Edge;*邻接点的定义*/
typedef struct AdjVNode *PtrToAdjVNode;struct AdjVNode{
vertex Adjv;*邻接点下标*/weightType weight;/*边权重*/
PtrToAdjVNode Next;/*指向下一个邻接点的指针*/
;
 
/*顶点表头结点的定义*/typedef struct Vnode{
PtrToAdjVNode FirstEdge;/*边表头指针*/DataType Data;
/*存项点的数据*/
/*注意:很多情况下，顶点无数据，此时Data可以不用出现*/AdjList[MaxVertexNum];/*AdjList是邻接表类型*/
*图结点的定义*/
typedef struct GNode *PtrToGNode;struct GNode{
int Nv;(*顶点数*/int Ne;*边数*/AdjList G;/*邻接表*/
};
typedef PtrToGNode LGraph;/*以邻接表方式存储的图类型*/

int Search(LGraph G,int e)
/*在图G中查找值为e的顶点，若找到，则返回该顶点在顶点向量中,返回-1*/
{
int i;
if(G->Nv<=0)
return -1;
for(i=0;i<G->Nv&8e!=G->G[i].Data;i++) ;if(i>=G->Nv)
return -1;else
return i;

LGraph CreateGraph( int VertexNum )
i/*初始化一个有VertexNum个顶点但没有边的图*/
vertex v;
LGraph Graph;
Graph = (LGraph)malloc( sizeof(struct GNode) );/*建立Graph->Nv = VertexNum;
Graph->Ne = 0;
/*初始化邻接表头指针*/
/*注意;这里默认顶点编号从0开始，到(Graph->Nv - 1)*/for (v=0; v<Graph->Nv; V++)
Graph->G[V].FirstEdge = NULL;
return Graph;

void InsertEdge( LGraph Graph,Edge E ){
PtrToAdjVNode NewNode;int i,j;
i=Search(Graph,E->V1);j=Search(Graph,E->V2);
/*插入边<v1, V2>*/
NewNode = (PtrToAdjvNode)malloc(sizeof(struct AdjVNode)) ;NewNode->AdjV = j;
NewNode->weight = E->weight;
NewNode->Next = Graph->G[i].FirstEdge;Graph->G[i].FirstEdge = NewNode;
/*若是无向图，还要插入边<V2,V1>*/
NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));NewNode->AdjV = i;
NewNode->weight = E->weight;
NewNode->Next = Graph->G[j].FirstEdge;Graph->G[j].FirstEdge = NewNode;
u

LGraph BuildGraph(){
LGraph Graph;Edge E;
Vertex v;int Nv,i;
printf("请输入顶点个数:\n");
scanf("%d"，8Nv);/*读入项点个数*/
Graph = CreateGraph(Nv);/*初始化有Nv个顶点但没有边的l/*如果顶点有数据的话，读入数据*/
for (v=0; v<Graph->Nv; V++)
{
printf("输入第‰d顶点\n",V+1);scanf( "%d"，&(Graph->G[M.Data)) ;
}
printf( "\n请输入边数:\n");
scanf( "%d",&(Graph->Ne) );*读入边数*/if ( Graph->Ne != 0 ) i/*如果有边*/
E = (Edge)malloc( sizeof(struct ENode) );/*建立边*读入边，格式为"起点终点权重"，插入邻接矩阵*/for (i=0; i<Graph->Ne; i++) i
printf("\n请输入边及权值:(n");
scanf( "%d %d %d"，E->V1,E->V2，E->weight);/*注意:如果权重不是整型，weight的读入格式要改InsertEdge( Graph，E );
}
)
return Graph;
void PrintGraph(LGraph G){
int i;
PtrToAdjVNode p;
printf( "\n输出邻接表:\n");for(i=0; i<G->Nv; i++)
{
printf("%d:%d",i,G->G[i].Data);p = G->G[i].FirstEdge;
while(p)
{
printf("->%d",p->AdjV);p=p->Next;
)
printf( "\n");
}
int main(){
LGraph G;
G=BuildGraph();PrintGraph(G);return 0;
}
