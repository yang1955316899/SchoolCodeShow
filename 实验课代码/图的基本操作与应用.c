//��������:ͼ���ڽӱ�洢��ʵ��
//���뻷��:Dev-C++ 5.5.3
//����:���
//����޸�:2020-12-13

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

typedef int Vertex;         /*�ö����±��ʾ����,Ϊ����*/
typedef int WeightType;
typedef char DataType;
*����洢������������Ϊ�ַ���
*�ߵĶ���*/
typedef struct ENode *PtrToENode;struct ENode{
Vertex V1,v2;*�����<V1,V2> */weightType weight;/*Ȩ��*/
;
typedef PtrToENode Edge;*�ڽӵ�Ķ���*/
typedef struct AdjVNode *PtrToAdjVNode;struct AdjVNode{
vertex Adjv;*�ڽӵ��±�*/weightType weight;/*��Ȩ��*/
PtrToAdjVNode Next;/*ָ����һ���ڽӵ��ָ��*/
;
 
/*�����ͷ���Ķ���*/typedef struct Vnode{
PtrToAdjVNode FirstEdge;/*�߱�ͷָ��*/DataType Data;
/*����������*/
/*ע��:�ܶ�����£����������ݣ���ʱData���Բ��ó���*/AdjList[MaxVertexNum];/*AdjList���ڽӱ�����*/
*ͼ���Ķ���*/
typedef struct GNode *PtrToGNode;struct GNode{
int Nv;(*������*/int Ne;*����*/AdjList G;/*�ڽӱ�*/
};
typedef PtrToGNode LGraph;/*���ڽӱ�ʽ�洢��ͼ����*/

int Search(LGraph G,int e)
/*��ͼG�в���ֵΪe�Ķ��㣬���ҵ����򷵻ظö����ڶ���������,����-1*/
{
int i;
if(G->Nv<=0)
return -1;
for(i=0;i<G->Nv&8e!=G->G[i].Data;i++) ;if(i>=G->Nv)
return -1;else
return i;

LGraph CreateGraph( int VertexNum )
i/*��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ*/
vertex v;
LGraph Graph;
Graph = (LGraph)malloc( sizeof(struct GNode) );/*����Graph->Nv = VertexNum;
Graph->Ne = 0;
/*��ʼ���ڽӱ�ͷָ��*/
/*ע��;����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1)*/for (v=0; v<Graph->Nv; V++)
Graph->G[V].FirstEdge = NULL;
return Graph;

void InsertEdge( LGraph Graph,Edge E ){
PtrToAdjVNode NewNode;int i,j;
i=Search(Graph,E->V1);j=Search(Graph,E->V2);
/*�����<v1, V2>*/
NewNode = (PtrToAdjvNode)malloc(sizeof(struct AdjVNode)) ;NewNode->AdjV = j;
NewNode->weight = E->weight;
NewNode->Next = Graph->G[i].FirstEdge;Graph->G[i].FirstEdge = NewNode;
/*��������ͼ����Ҫ�����<V2,V1>*/
NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));NewNode->AdjV = i;
NewNode->weight = E->weight;
NewNode->Next = Graph->G[j].FirstEdge;Graph->G[j].FirstEdge = NewNode;
u

LGraph BuildGraph(){
LGraph Graph;Edge E;
Vertex v;int Nv,i;
printf("�����붥�����:\n");
scanf("%d"��8Nv);/*����������*/
Graph = CreateGraph(Nv);/*��ʼ����Nv�����㵫û�бߵ�l/*������������ݵĻ�����������*/
for (v=0; v<Graph->Nv; V++)
{
printf("����ڡ�d����\n",V+1);scanf( "%d"��&(Graph->G[M.Data)) ;
}
printf( "\n���������:\n");
scanf( "%d",&(Graph->Ne) );*�������*/if ( Graph->Ne != 0 ) i/*����б�*/
E = (Edge)malloc( sizeof(struct ENode) );/*������*����ߣ���ʽΪ"����յ�Ȩ��"�������ڽӾ���*/for (i=0; i<Graph->Ne; i++) i
printf("\n������߼�Ȩֵ:(n");
scanf( "%d %d %d"��E->V1,E->V2��E->weight);/*ע��:���Ȩ�ز������ͣ�weight�Ķ����ʽҪ��InsertEdge( Graph��E );
}
)
return Graph;
void PrintGraph(LGraph G){
int i;
PtrToAdjVNode p;
printf( "\n����ڽӱ�:\n");for(i=0; i<G->Nv; i++)
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
