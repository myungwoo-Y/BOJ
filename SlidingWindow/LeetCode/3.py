import os
import sys
from collections import Counter
from collections import deque
from functools import cmp_to_key
from queue import PriorityQueue
from bisect import bisect_left
from itertools import combinations, permutations

if os.path.exists("in.txt"):
    sys.stdin = open("in.txt")


def printe(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)


def get_back(l):
    return l[len(l) - 1]


def is_empty(l):
    return len(l) == 0


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = [0] * 128

        l, r = 0, 1
        ans = 0

        if len(s) == 0:
            return 0

        while r <= len(s):
            ch = s[r-1]
            chars[ord(ch)] += 1

            while chars[ord(ch)] > 1:
                removed_ch = s[l]
                chars[ord(removed_ch)] -= 1
                l += 1

            ans = max(ans, r - l)

            r += 1

        return ans




solution = Solution()

print(solution.lengthOfLongestSubstring(""))

