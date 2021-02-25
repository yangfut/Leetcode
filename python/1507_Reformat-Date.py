class Solution:
    def reformatDate(self, date: str) -> str:
        date = date.split(" ")
        dict_Month = {"Jan":"01", 
                      "Feb":"02", 
                      "Mar":"03", 
                      "Apr":"04",
                      "May":"05",
                      "Jun":"06",
                      "Jul":"07", 
                      "Aug":"08",
                      "Sep":"09",
                      "Oct":"10",
                      "Nov":"11",
                      "Dec":"12"}
        
        if len(date[0])<4: date[0] = "0"+date[0]
        return date[2]+"-"+dict_Month[date[1]]+"-"+date[0][:2]
      
 def main():
  sol = Solution()
  
  date = "20th Oct 2052"
  #Output: "2052-10-20"
  print(sol.reformatDate(date))
  
  date = "6th Jun 1933"
  #Output: "1933-06-06"
  print(sol.reformatDate(date))

if __name__ == "__main__":
  main()
