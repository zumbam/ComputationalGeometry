close all;


A =[
   59.9798  310.1933
   15.6250  491.2127
   16.6331  515.8172
   29.7379  565.0264
   66.0282  654.6573
   87.1976  688.0492
  177.9234  830.4042
  233.3669  895.4306
  248.4879  905.9754
  320.0605  942.8822
  405.7460  974.5167
  521.6734  993.8489
  618.4476  949.9121
  660.7863  927.0650
  681.9556  913.0053
  866.4315  688.0492
  929.9395  591.3884
  929.9395  498.2425
  912.8024  392.7944
  887.6008  311.9508
  832.1573  192.4429
  732.3589   72.9350
  690.0202   50.0879
  630.5444   21.9684
  597.2782   11.4236
  524.6976   16.6960
  482.3589   21.9684
  456.1492   27.2408
  424.8992   34.2707
  346.2702   55.3603
  295.8669   74.6924
  239.4153   97.5395
  179.9395  127.4165
  128.5282  167.8383
  103.3266  206.5026
   85.1815  243.4095
   67.0363  283.8313
   59.9798  310.1933
]
% A= [  0     0
%     10     0
%     10    10
%     0    10
%     0     0]
edges = zeros([size(A, 1)-1, 2]);
normals = zeros([size(A, 1)-1, 2]);
for i = 1:size(A,1)-1
    edges(i, :) = A(i + 1, :) - A(i, :);
    normals(i, :) = [-edges(i, 2), edges(i,1)];
end
normals = normalize(normals,2,'norm',2)
f = @(x, y) min(dot([x y] - A(2:end,:),normals, 2));

min_x=min(A(:,1));
min_y=min(A(:,2));
max_x=max(A(:,1));
max_y=max(A(:,2));

[x,y] = meshgrid(linspace(min_x,max_x,50),linspace(min_y,max_y,50));
z =arrayfun(f,x,y);
figure('name', 'contour of min function');
contour(x,y,z, 30)
r = @(x, y) all(dot([x y] - A(2:end,:),normals, 2)>=0);
region =arrayfun(r,x,y);
image = zeros(size(region));
image(region) = 1;
figure('name','contour of borders')

patch('x', [-1 11], 'y', [-1 11], 'FaceColor','black','EdgeColor', 'white')
patch('x', A(:,1),'y', A(:,2), 'FaceColor', 'red')
% !!!!!!!the - sign has to be changed for using the test polygon
% because of the polygon Point order !!!!!!!!!
normals = -normals

% get number of edge constraights
num_polygon_contraints = size(normals, 1);
% init constraint array 
constraint = zeros([num_polygon_contraints*2, 3]);
constraint_condition = zeros([num_polygon_contraints*2, 1]);
% first dimisions are the borders for the polygon
% A = [n_x n_y 0] B= [-p_x * n_x  -p_y * n_y]
% constraint(1:num_polygon_contraints, 1:2) = -normals;
% constraint_condition(1:num_polygon_contraints) = -dot(A(2:end,:), normals, 2);
% the following are the contraint for the min r
% it will be expressed as follows r <= d(x, y)
% d (x, y) = x * n_x + y * n_y - (p_x * n_x + p_y * n_y)
% therefore it will be expressed as constraint
% - x * n_x - y * n_y + r <= - (p_x * n_x + p_y * n_y)
% so the Matrix A contains [-n_x -n_y 1] 
% and B contains [-p_x * n_x  -p_y * n_y]
constraint(num_polygon_contraints+1:end, 1:2) = -normals(:,:);
constraint(num_polygon_contraints+1:end, 3) = 1;
constraint_condition(num_polygon_contraints+1: end) = -dot(A(2:end,:), normals, 2);

f = [0 0 -1]
c = linprog(f,constraint,constraint_condition)

t = linspace(0, 2*pi);
r = 1;
x = c(1) + c(3)*cos(t);
y = c(2) + c(3)*sin(t);
patch(x, y, 'g')
axis equal


