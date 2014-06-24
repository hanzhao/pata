#!/usr/bin/env ruby
_ = gets.to_i
ans = gets.split.map { |x| Rational(x) }.inject { |s, x| s += x }
ans = [ans.truncate, ans - ans.truncate].map { |x| x == 0 ? nil : x }.compact
puts ans.size == 0 ? 0 : ans.join(' ')
