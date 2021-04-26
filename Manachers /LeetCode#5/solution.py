import os
import sys
from collections import Counter
from collections import deque
from functools import cmp_to_key
from queue import PriorityQueue
from bisect import bisect_left
from itertools import combinations, permutations
from typing import List


def get_back(l):
    return l[len(l) - 1]


def is_empty(l):
    return len(l) == 0

class Solution:

    def addOddString(self, s: str) -> str:
        ret = "#"
        for ch in s:
            ret += ch + "#"
        return ret

    def longestPalindrome(self, s: str) -> str:
        ans = s[0]
        added_str = self.addOddString(s)

        str_len = len(added_str)
        palin_list = [0 for r in range(str_len)]
        c = 0
        r = 0
        max_len = 0

        for i in range(str_len):
            mirror = (2*c) - i

            if i < r:
                palin_list[i] = min(r-i, palin_list[mirror])

            a = i - (1 + palin_list[i])
            b = i + (1 + palin_list[i])

            while a >= 0 and b < str_len and added_str[a] == added_str[b]:
                palin_list[i] += 1
                a -= 1
                b += 1

            if i + palin_list[i] > r:
                c = i
                r = i + palin_list[i]

                if palin_list[i] > max_len:
                    max_len = palin_list[i]
                    ans = added_str[a+1:b]



        return ans.replace("#", "")


solution = Solution()

