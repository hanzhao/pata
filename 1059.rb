noprime = []; prime = [2]
ans = []
3.step(49999, 2) do |i|
  prime << i  if !noprime[i]
  prime.each do |p|
    break if i * p > 49999
    noprime[i * p] = true
    break if i % p == 0
  end
end
n = gets.chomp.to_i
print n, '='
times = 0
prime.each do |p|
  break if p > n
  times = 0
  while n % p == 0
    times += 1
    n /= p
  end
  if times > 1
    ans << "#{p}^#{times}"
  elsif times == 1
    ans << p
  end
end
ans << n if n != 1 || (n == 1 && ans.empty?)
puts ans.join('*')
