import java.util.*;

class LongEqualSub {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String containing 0s & 1s: ");
        String str = sc.nextLine();
        Map<Integer,Integer> valMap = new HashMap<>();
        valMap.put(0,-1);
        int maxLen = 0, val = 0;
        
        for(int index = 0; index < str.length(); index++) {
            val += (str.charAt(index)=='1')? 1 : -1;
            if (!valMap.containsKey(val)) {
                valMap.put(val,index);
            } else {
                int newIndex = index-valMap.get(val);
                maxLen = Math.max(maxLen,newIndex);
            }
        }
        System.out.println("Length of Longest Substring is : " + maxLen);
    }
}