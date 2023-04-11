// https://leetcode.cn/problems/random-pick-with-weight/
  // 二分法
  // 寻找左右边界

class Solution(object):

  def __init__(self, w):
      """
      :type w: List[int]
      """
      # self.pre_sum = list()
      self.pre_sum = [0, ]
      sum = 0
      for item in w:
          sum += item
          self.pre_sum.append(sum)


  def pickIndex(self):
      """
      :rtype: int
      """
      return self.rand()

  def rand(self):
      target = random.randint(0, self.pre_sum[-1]-1)
      left_idx = self.find_left(target)
      return left_idx

  def find_left(self, target):
      left = 0
      right = len(self.pre_sum) - 1
      while left <= right:
          mid = int ((left + right)/2)
          if self.pre_sum[mid] == target:
              return mid
          elif self.pre_sum[mid] < target:
              left = mid + 1
          elif self.pre_sum[mid] > target:
              right = mid - 1
      return right
            




# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
