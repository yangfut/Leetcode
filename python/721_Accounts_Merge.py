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
