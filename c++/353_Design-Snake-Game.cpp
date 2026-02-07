// Linked List + Hash Map
class SnakeGame {
public:
    class Node{
    public:
        int rPost, cPost;
        Node* next;
        Node* prev;
    
        Node(int r, int c){
            rPost = r;
            cPost = c;
            next = nullptr;
            prev = nullptr;
        }
    };

    int _w, _h, score;
    queue<pair<int,int>> foodQueue;
    set<pair<int,int>> bodySet;
    Node* head = nullptr;
    Node* tail = nullptr;

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        score = 0;
        _w = width;
        _h = height;
        for (auto& p : food) foodQueue.push(make_pair(p[0], p[1]));
        bodySet.insert({0,0});
        head = new Node(0,0);
        tail = head;
    }
    
    ~SnakeGame(){
        while(head){
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int move(string direction) {
        int dr = 0, dc = 0;
        if (direction == "R") dc = 1;
        else if (direction == "L") dc = -1;
        else if (direction == "U") dr = -1;
        else if (direction == "D") dr = 1;
        else return -1;

        // check hit wall
        int nr = head->rPost + dr;
        int nc = head->cPost + dc;
        if(nr < 0 || nr >= _h || nc < 0 || nc >= _w) return -1;

        bool hitFood = false;
        if(!foodQueue.empty() &&
            nr == foodQueue.front().first &&
            nc == foodQueue.front().second){
            hitFood = true;
            score += 1;
            foodQueue.pop();
        }

        if(!hitFood){
            bodySet.erase({tail->rPost, tail->cPost});
        }

        // Check body collison
        if(bodySet.count({nr, nc})) return -1;

        // Add new head
        Node* next = new Node(nr, nc);
        next->next = head;
        head->prev = next;
        head = next;
        bodySet.insert({nr, nc});

        if(!hitFood){
            Node* to_remove = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete to_remove;
        }
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */


 // dequeue + Hash map
class SnakeGame {
public:

    int width, height, score = 0;
    deque<pair<int,int>> snake;
    queue<pair<int,int>> foodQue;
    unordered_set<int> bodySet;
    SnakeGame(int width, int height, vector<vector<int>>& food): width(width), height(height) {
        for(auto& f : food) foodQue.push({f[0], f[1]});
        bodySet.insert(encode(0,0));
        snake.push_front({0,0});
    }
    
    int move(string direction) {
        int dr = 0, dc = 0;
        if (direction == "U") dr = -1;
        else if (direction == "D") dr = 1;
        else if (direction == "R") dc = 1;
        else if (direction == "L") dc = -1;

        auto [hr, hc] = snake.front();
        int nr = hr + dr;
        int nc = hc + dc;

        if(nr < 0 || nr >= height || nc < 0 || nc >= width) return -1;

        bool eatFood = false;
        if(!foodQue.empty() && foodQue.front().first == nr && foodQue.front().second == nc){
            eatFood = true;
            ++score;
            foodQue.pop();
        }

        // Update tail position before collison check
        if(!eatFood){
            auto& [br, bc] = snake.back();
            bodySet.erase(encode(br, bc));
        }

        int nextPost = encode(nr, nc);
        // body collison check
        if(bodySet.count(nextPost)) return -1;

        // Update head
        snake.push_front({nr, nc});
        bodySet.insert(nextPost);

        // Update tail
        if(!eatFood) snake.pop_back();

        return score;
    }
private:
    int encode(int r, int c){
        return r * width + c;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */