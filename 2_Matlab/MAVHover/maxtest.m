syms one two three
mat1 = [cos(one),sin(one);-sin(one),cos(one)];
mat2 = [cos(two),sin(two);-sin(two),cos(two)];
mat3 = [cos(three),sin(three);-sin(three),cos(three)];

simplify(mat1*mat2*mat3)