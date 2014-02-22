class Rec
    attr_accessor :name, :month, :time, :status
    def initialize(a)
        @name = a[0]
        t = a[1].split(":")
        @month = t[0].to_i
        @time = "#{t[1]}:#{t[2]}:#{t[3]}"
        @status = a[2] == "on-line" ? true : (a[2] == "off-line" ? false : nil)
    end
end
price = gets.chomp.split(" ").collect { |x| x.to_f / 100.0 }
n = gets.chomp.to_i
all = []
n.times { all << Rec.new(gets.chomp.split(" ")) }
all.sort! { |a,b| a.name == b.name ? a.time <=> b.time : a.name <=> b.name }
cost = 0.0; fir = true; last = nil
all.each { |x|
    if last && x.name != last.name
        print "Total amount: $%.2f\n" % cost if cost != 0.0
        fir = true; cost = 0.0; last = nil
    end
    if x.status == false
        if last && last.status
            f = last.time.split(":").collect &:to_i
            t = x.time.split(":").collect &:to_i
            print x.name, " ", "%02d" % x.month, "\n" if fir
            fir = false
            total = (t[0] - f[0]) * 1440 + (t[1] - f[1]) * 60 + t[2] - f[2]
            thiscost = 0.0
            if t[0] != f[0] || t[1] != f[1]
                thiscost += price[f[1]] * (60 - f[2])
                f[2] = 0; f[1] += 1
                if f[1] == 24
                    f[1] = 0
                    f[0] += 1
                end
                thiscost += price[t[1]] * t[2]
                t[2] = 0
                while t[0] != f[0] || t[1] != f[1]
                    thiscost += price[f[1]] * 60
                    f[1] += 1
                    if f[1] == 24
                        f[1] = 0
                        f[0] += 1
                    end
                end
            end
            thiscost += price[f[1]] * (t[2] - f[2])
            print last.time, " ", x.time, " ", total, " ", "$%.2f" % thiscost, "\n"
            cost += thiscost
        end
    end
    last = x
}
print "Total amount: $%.2f\n" % cost if last && cost != 0.0

