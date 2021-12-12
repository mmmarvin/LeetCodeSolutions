class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] ret = new int[A.length];
        ArrayList<Integer> oddList = new ArrayList<Integer>();

        int retPos = 0;
        for(int n : A) {
            if(n % 2 == 0) {
                ret[retPos++] = n;
            } else
                oddList.add(n);
        }

        for(int n : oddList) {
            ret[retPos++] = n;
        }

        return ret;
    }
}

public class SortArray
{
    public static void main(String[] args)
    {

    }
}