class Solution:
    def accountsMerge(self, accounts):
        def find_root(idx):
            if idx != parent[idx]:
                rx = find_root(parent[idx])
                parent[idx] = rx
            return parent[idx]
        def union(a, b):
            parent[find_root(b)] = parent[find_root(a)]
            
        em2id = {}
        id2em = {}
        id2acc = {}
        
        for acc in accounts:
            for em in acc[1:]:
                if em not in em2id:
                    id2em[len(em2id)] = em
                    id2acc[len(em2id)] = acc[0]
                    em2id[em] = len(em2id)
                    
        #Create unique email-to-id dictonary
        #Qucik Union O(NM)
        parent = [x for x in range(len(em2id))]
        for acc in accounts:
            em_root = em2id[acc[1]]
            for em in acc[2:]:
                union(em_root, em2id[em])
                
        ans =[]
        for idx in range(len(parent)):
            if idx == parent[idx]:
                tmp = []
                for i in range(len(parent)):
                    if find_root(i) == parent[idx]:
                        tmp.append(id2em[i])
                ans.append([id2acc[idx]]+sorted(tmp))
        return ans
'''
class Solution:
    def accountsMerge(self, accounts):
        dict = {}
        for acc in accounts:
            if acc[0] in dict:
                dict[acc[0]].append(set(acc[1:]))
            else:            
                dict[acc[0]] = [set(acc[1:])]
        ans =[]
        for key, listSet in dict.items():
            while listSet:
                emailSet = listSet.pop()
                condition = True
                while condition:
                    condition = False
                    for idx in range(len(listSet)):
                        if emailSet & listSet[idx]:
                            emailSet.update(listSet.pop(idx))
                            condition = True
                            break
                ans.append([key] + sorted(emailSet))
        return sorted(ans, key = lambda x:x[0])
'''
def main():
    s = Solution()

    accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], 
                ["John", "johnnybravo@mail.com"], 
                ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
                ["Mary", "mary@mail.com"]]
    
    #Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
                #["John", "johnnybravo@mail.com"], 
                #["Mary", "mary@mail.com"]]
    print(s.accountsMerge(accounts))      
    accounts = [["Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"],
                ["Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"],
                ["Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"],
                ["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"],
                ["Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"]]
    
    #Output: [["Alex","Alex0@m.co","Alex4@m.co","Alex5@m.co"],
                #["Ethan","Ethan0@m.co","Ethan3@m.co"],
                #["Gabe","Gabe0@m.co","Gabe2@m.co","Gabe3@m.co","Gabe4@m.co"],
                #["Kevin","Kevin2@m.co","Kevin4@m.co"]]
    print(s.accountsMerge(accounts))
    accounts = [["David","David0@m.co","David1@m.co"],
                ["David","David3@m.co","David4@m.co"],
                ["David","David4@m.co","David5@m.co"],
                ["David","David2@m.co","David3@m.co"],
                ["David","David1@m.co","David2@m.co"]]
    #Output: [["David","David0@m.co","David1@m.co","David2@m.co","David3@m.co","David4@m.co","David5@m.co"]]
    print(s.accountsMerge(accounts))
    
if __name__ == '__main__':
    main()


