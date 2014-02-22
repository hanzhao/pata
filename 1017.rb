# TLE
class Person
    attr_accessor :arrive, :time, :t
    def initialize(a)
        @arrive = a[0]; @time = a[1].to_i
        t = @arrive.split(":").collect &:to_i
        @t = t[0] * 3600 + t[1] * 60 + t[2]
    end
end
a = []
seconds = 0
n, m = gets.chomp.split(" ").collect &:to_i
win = Array.new(m) { nil }
etime = Array.new(m) { nil }
n.times { a << Person.new(gets.chomp.split(" ")) }
a.sort_by! { |x| x.arrive }
a.each_index { |i|
    if a[i].arrive < "08:00:00"
        seconds += 28800 - a[i].t
        a[i].arrive = "08:00:00"
        a[i].t = 28800
    elsif a[i].arrive > "17:00:00"
        a[i] = nil
    end
}
a.compact!
tail = 0
now = 28800
full = false
wait = []
can = []
last = 61200
while now <= last do
    can.clear
    win.each_index { |i|
        if win[i] && now == etime[i]
            win[i] = nil
        end
        if !win[i]
            can << i
        end
    }
    while tail < a.length && now == a[tail].t
        wait << a[tail]
        tail += 1
    end
    if !wait.empty?
        can.each { |x|
            if !wait.empty?
                win[x] = wait.shift
                etime[x] = win[x].time * 60 + now
                last = etime[x] if last < etime[x]
            end
        }
    end
    min = 111111
    win.each_index { |i|
        min = etime[i] if win[i] && min > etime[i]
    }
    min = a[tail].t if tail < a.length && min > a[tail].t
    seconds += wait.length * (min - now)
    now = min
end
puts "%.1f" % (seconds / 60.0 / a.length)

