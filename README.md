# CS112.M11.KHTN
Môn học: phân tích  và thiết kế thuật toán | Đại học CNTT

Nội dung
1. Giới thiệu:
- Bộ test là gì? Tại sao cần?
- Tính đúng đắn và hiệu năng.
2. Viết trình chấm
- Trình sinh test: là 1 chương trình sinh test ngẫu nhiên theo yêu cầu và giới hạn của đề
  + Random số
  ```c++
  int randomNumber(int a, int b){
      return rand() % (b - a + 1) + a;
  }
  ```
  + Random số lớn
  ```c++
  mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
  #define rand rd

  long long randomLLNumber(long long l, long long h) {
      assert(l <= h);
      return l + rd() * 1LL * rd() % (h - l + 1);
  }
  ```
  + Random mảng
  ```c++
  void randomArray(int n, int *arr, int a, int b){
      for (int i = 0; i < n; i++){
          arr[i] = randomNumber(a,b);
      }
  }
  ```
  + Random ký tự từ 'a' đến 'z'
  ```c++
  char randomCharacter(){
      return 'a' + rand() % 25;
  }
  ```
  + Random chuỗi
  ```c++
  string randomString(int len){
      string res = "";
      for (int i = 0; i < len; i++){
          res.push_back(randomCharacter());
      }
      return res;
  }
  ```
  + Random cây không trọng số
  ```c++
  set< pair<int,int> > unweighted_tree_generation(int n){
      vector< vector<int> > adj(n);
      set< pair<int,int> > container;
      for (int i = 0; i < n-1; i++){
          int u = rand() % n;
          int v =  rand() % n;
          pair<int,int> p = {u,v};
          adj[u].push_back(v);

          while (container.find(p) != container.end()
                      || isCyclic(n, adj) == true)
              {
                  adj[u].pop_back();
                  u = rand() % n;
                  v = rand() % n;
                  p = {u,v};
                  adj[u].push_back(v);
              }
          container.insert(p);
      }
      return container;
  }
  ```
  + Random độ thị có hướng không trọng số
  ```c++
  set< pair<int,int> > directed_unweighted_graph_generation(int n, int maxEdge){
      set< pair<int,int> > container;
      for (int j=1; j<=maxEdge; j++)
      {
          int a = 1 + rand() % n;
          int b = 1 + rand() % n;
          pair<int, int> p = make_pair(a, b);

          while (container.find(p) != container.end())
          {
              a = 1 + rand() % n;
              b = 1 + rand() % n;
              p = make_pair(a, b);
          }
          container.insert(p);
      }
      return container;
  }
  ```
  + 
- Lời giải 1, lời giải 2: Lời giải 1 là lời giải tối ưu mà chúng ta cần kiểm tra về tính đúng đắn và hiệu suất
Lời giải 2 là lời giải đúng dễ dàng cài đặt không nhất thiết phải nhanh, thường sẽ cài bằng các thuật toán trâu

- Trình so test: Chương trình này có nhiệm vụ duyệt N lần, mỗi lần duyệt thì chạy trình sinh test rồi chạy 2 chương trình lời giải 1 và lời giải 2 so sánh output mà đưa ra kết quả\
  + Thư mục example sẽ chứa các file ví dụ trong slide 
  + File template.cpp là file template trình chấm

- Nguồn tham khảo: 
  + https://vnoi.info/wiki/algo/skill/viet-trinh-cham.md
  + geeksforgeeks testcase generation: https://www.geeksforgeeks.org/test-case-generation-set-1-random-numbers-arrays-and-matrices/
  + Và nhiều nguồn trong và ngoài nước khác
3. Ví dụ:
- problem 7.08: https://khmt.uit.edu.vn/wecode/it001.2020/assignment/229/332
- khangtd.ConnectedComponents: https://khmt.uit.edu.vn/wecode/it003.2021/assignment/67/807
- numbertree: https://open.kattis.com/problems/numbertree

