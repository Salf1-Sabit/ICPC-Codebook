/** 1. _2D_segment_tree<long long> _2D_seg_tree(a);
  * 2. _2D_seg_tree.buildx(1, 0, n - 1);
  * 3. Note : Make sure that the segment tree type and the 
       vector type must mathc. E.g If, struct _2D_segment_tree <long long> 
	   then, vector must be vector<long long>
  *	4. Note : While using index for answer. Make sure to use them as (0 based)
  * 5. now, you're good to go.
 **/
template <typename T> 
struct _2D_segment_tree { 
  int n, m; 
  vector<vector<T>> a, t;
  _2D_segment_tree (vector<vector<T>> a) { 
    this -> a = a;
    this -> n = (int) a.size();
    this -> m = (int) a[0].size();
    t.assign(n << 2, vector<T>(m << 2));
  }
  void build_y (int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
      if (lx == rx) { 
        t[vx][vy] = a[lx][ly];
      } else { 
        t[vx][vy] = t[(vx << 1)][vy] + t[(vx << 1) + 1][vy];
      }
    } else {
      int my = (ly + ry) >> 1;
      build_y(vx, lx, rx, (vy << 1), ly, my);
      build_y(vx, lx, rx, (vy << 1) + 1, my + 1, ry);
      t[vx][vy] = t[vx][(vy << 1)] + t[vx][(vy << 1) + 1];
    }
  }
  /* Prepares the _2D segment tree 
   * _2D_seg_tree.build_x(1, 0, n - 1); */
  void build_x (int vx, int lx, int rx) {
    if (lx != rx) {
      int mx = (lx + rx) >> 1;
      build_x((vx << 1), lx, mx);
      build_x((vx << 1) + 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m - 1);
  }
  T sum_y (int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) { 
      return (T) 0;
    }
    if (ly == tly && try_ == ry) { 
      return t[vx][vy];
    }
    int tmy = (tly + try_) >> 1;
    return sum_y(vx, (vy << 1), tly, tmy, ly, min(ry, tmy))
       + sum_y(vx, (vy << 1) + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
  }
  /* Returns the sum of a sub-matrix from, 
   * [(left_x, left_y) top_left corner] to [(right_x, right_y) bottom_right corner]
   * _2D_seg_tree.sum_x(1, 0, n - 1, --left_x, --right_x, --left_y, --right_y) -> 0 based indexing */
  T sum_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx) { 
      return 0;
    }
    if (lx == tlx && trx == rx) { 
      return sum_y(vx, 1, 0, m - 1, ly, ry);
    }
    int tmx = (tlx + trx) >> 1;
    return sum_x((vx << 1), tlx, tmx, lx, min(rx, tmx), ly, ry)
       + sum_x((vx << 1) + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
  }
  void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, T new_val) {
    if (ly == ry) {
      if (lx == rx) { 
        t[vx][vy] = new_val;
      } else { 
        t[vx][vy] = t[(vx << 1)][vy] + t[(vx << 1) + 1][vy];
      }
    } else {
      int my = (ly + ry) >> 1;
      if (y <= my) { 
        update_y(vx, lx, rx, (vy << 1), ly, my, x, y, new_val);
      } else { 
        update_y(vx, lx, rx, (vy << 1) + 1, my + 1, ry, x, y, new_val);
      }
      t[vx][vy] = t[vx][(vy << 1)] + t[vx][(vy << 1) + 1];
    }
  }
  /* Updates a particular cell of the matrix - (x_axis, y_axis)
   * _2D_seg_tree.update_x(1, 0, n - 1, --left_x, --left_y, new_val); */
  void update_x (int vx, int lx, int rx, int x, int y, T new_val) {
    if (lx != rx) {
      int mx = (lx + rx) >> 1;
      if (x <= mx) { 
        update_x((vx << 1), lx, mx, x, y, new_val);
      } else { 
        update_x((vx << 1) + 1, mx + 1, rx, x, y, new_val);
      }
    }
    update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
  }
};
