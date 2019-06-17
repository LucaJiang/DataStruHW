%MSP_TSP_���۰Ĵ�����
%����о���
%%init
clc,clear
num_city=11;
scale_re=20;%20km
pic=imread('��������ͼ.PNG');

%%scale
imshow(pic,'InitialMagnification',80);
text(10,10,'1.��������ߵ���˺��Ҷ�','Color','r','FontSize',10)
scale_input=ginput(2)
scale=norm(scale_input(1,:)-scale_input(2,:),2)
ratio=scale_re/scale
%dis_re=dis*ratio

%%city distance
text(10,50,'2.���ε������:��� ���� ���� ���� �麣 ��ɽ ���� ��ݸ ��ɽ ���� ����','Color','b','FontSize',10)
city_pos=ginput(num_city)
%text(10,90,'3.�����ɣ�enter���˳�','Color','g','FontSize',10)
close
city_dis=zeros(11);
for i=1:num_city
    for j=i:num_city
        city_dis(i,j)=norm(city_pos(i,:)-city_pos(j,:),2);
    end
end
disp('11���о���(KM)')
disp('��� ���� ���� ���� �麣 ��ɽ ���� ��ݸ ��ɽ ���� ����')
city_realdis=city_dis.*ratio
city_realdis_int=round(city_realdis);

%MST
%init graph
name={'���','����','���� ','����','�麣','��ɽ','����','��ݸ','��ɽ','����','����'}';
g=graph(city_realdis,name,'upper'); %������

%mst prim
gp1=plot(g,'NodeColor','y');
title('MST-Prim')
%tree,predecessor nodes
[t1,pred1]=minspantree(g,'Method','dense');%����ͼprim
highlight(gp1,t1)

%mst kruskal
gp2=plot(g,'NodeColor','y');
title('MST-Kruskal')
[t2,pred2]=minspantree(g,'Method','sparse');%ϡ��ͼkruskal
highlight(gp2,t2)
hold off

%TSP
cost=city_realdis'+city_realdis;
tsp_ga('xy',city_pos,'dmat',cost)
