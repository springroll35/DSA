t = int(input())

for i in range(t):
	s = input()
	n = len(s)
	dp = []
	dp.append(int(s[0]))
	ans = dp[0]
	for i in range(1, n):
		num = int(s[i])
		dp.append(num * (i+1) + 10 * dp[i-1])
		ans += dp[i]
	print(ans)
	
	
	