class TreeNode:
    def __init__(self, name):
        self.name = name
        self.isLive = True
        self.children = []

class ThroneInheritance:

    def __init__(self, kingName):
        self.kingName = kingName
        self.dict = {kingName: TreeNode(kingName)}

    def birth(self, parentName, childName):
        self.dict[childName] = TreeNode(childName)
        self.dict[parentName].children.append(childName)
        
    def death(self, name: str):
        self.dict[name].isLive = False
    
    def getInheritanceOrder(self):
        order = []
        
        def dfs_tree(order, myDict, node):
            if myDict[node].isLive:
                order.append(node)
    
            for child in myDict[node].children:
                dfs_tree(order, myDict, child)
                        
        dfs_tree(order, self.dict, self.kingName)
        
        return order


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
    
    
def main():
    
    t = ThroneInheritance("king") # order: king
    t.birth("king", "andy") # order: king > andy
    t.birth("king", "bob") # order: king > andy > bob
    t.birth("king", "catherine") # order: king > andy > bob > catherine
    t.birth("andy", "matthew") # order: king > andy > matthew > bob > catherine
    t.birth("bob", "alex") # order: king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha") # order: king > andy > matthew > bob > alex > asha > catherine
    
    for key in t.dict:
        print(key, " :", t.dict[key].children)
    print(t.getInheritanceOrder()) # return ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
    t.death("bob") # order: king > andy > matthew > bob > alex > asha > catherine
    print(t.getInheritanceOrder()) # return ["king", "andy", "matthew", "alex", "asha", "catherine"]
    

if __name__ == '__main__':
    main()
