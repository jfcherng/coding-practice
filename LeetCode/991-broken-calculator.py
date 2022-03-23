class Solution:
    def brokenCalc(self, start: int, target: int) -> int:
        # Some reasons why we do it in a reversed way:
        #   - It's hard to determinate when you should start to `*2`.
        #   - It's obvious that odd `target` must come from `-1` operation.
        #   - When do it reversely, we can always prefer `/2` if `target` is even.
        steps = 0

        while target > start:
            if target & 1:
                target += 1
            else:
                target >>= 1
            steps += 1

        return steps + (start - target)


s = Solution()

res = s.brokenCalc(2, 3)
print(f"{res = }")

res = s.brokenCalc(3, 1)
print(f"{res = }")

res = s.brokenCalc(1, 1000000000)
print(f"{res = }")
