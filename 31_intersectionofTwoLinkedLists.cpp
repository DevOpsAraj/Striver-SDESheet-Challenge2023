// Code Studio - Intersection of Two Linked Lists

// Java Code

/*
public class Solution {
    public static int findIntersection(Node firstHead, Node secondHead) {
        //Write your code here
        if(firstHead==null || secondHead==null){
            return 0;
        }
        Node a = firstHead;
        Node b = secondHead;

        while(a!=b){
            a = a==null ? secondHead:a.next;
            b = b==null ? firstHead:b.next;
        }
        return a.data;
    }
}
*/