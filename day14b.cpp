#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

/*
const string input = "\

";
*/
/*
const string input = "\
        10 ORE => 10 A\n\
        1 ORE => 1 B\n\
        7 A , 1 B => 1 C\n\
        7 A , 1 C => 1 D\n\
        7 A , 1 D => 1 E\n\
        7 A , 1 E => 1 FUEL\n\
";*/
/*
const string input = "\
        9 ORE => 2 A\n\
        8 ORE => 3 B\n\
        7 ORE => 5 C\n\
        3 A , 4 B => 1 AB\n\
        5 B , 7 C => 1 BC\n\
        4 C , 1 A => 1 CA\n\
        2 AB , 3 BC , 4 CA => 1 FUEL\n\
";
*/

/*
const string input = "\
        157 ORE => 5 NZVS\n\
        165 ORE => 6 DCFZ\n\
        44 XJWVT , 5 KHKGT , 1 QDVJ , 29 NZVS , 9 GPVTF , 48 HKGWZ => 1 FUEL\n\
        12 HKGWZ , 1 GPVTF , 8 PSHF => 9 QDVJ\n\
        179 ORE => 7 PSHF\n\
        177 ORE => 5 HKGWZ\n\
        7 DCFZ , 7 PSHF => 2 XJWVT\n\
        165 ORE => 2 GPVTF\n\
        3 DCFZ , 7 NZVS , 5 HKGWZ , 10 PSHF => 8 KHKGT\n\
";
*/
/*
const string input = "\
        2 VPVL , 7 FWMGM , 2 CXFTF , 11 MNCFX => 1 STKFG\n\
        17 NVRVD , 3 JNWZP => 8 VPVL\n\
        53 STKFG , 6 MNCFX , 46 VJHF , 81 HVMC , 68 CXFTF , 25 GNMV => 1 FUEL\n\
        22 VJHF , 37 MNCFX => 5 FWMGM\n\
        139 ORE => 4 NVRVD\n\
        144 ORE => 7 JNWZP\n\
        5 MNCFX , 7 RFSQX , 2 FWMGM , 2 VPVL , 19 CXFTF => 3 HVMC\n\
        5 VJHF , 7 MNCFX , 9 VPVL , 37 CXFTF => 6 GNMV\n\
        145 ORE => 6 MNCFX\n\
        1 NVRVD => 8 CXFTF\n\
        1 VJHF , 6 MNCFX => 4 RFSQX\n\
        176 ORE => 6 VJHF\n\
";*/
/*
const string input = "\
        171 ORE => 8 CNZTR\n\
        7 ZLQW , 3 BMBT , 9 XCVML , 26 XMNCP , 1 WPTQ , 2 MZWV , 1 RJRHP => 4 PLWSL\n\
        114 ORE => 4 BHXH\n\
        14 VRPVC => 6 BMBT\n\
        6 BHXH , 18 KTJDG , 12 WPTQ , 7 PLWSL , 31 FHTLT , 37 ZDVW => 1 FUEL\n\
        6 WPTQ , 2 BMBT , 8 ZLQW , 18 KTJDG , 1 XMNCP , 6 MZWV , 1 RJRHP => 6 FHTLT\n\
        15 XDBXC , 2 LTCX , 1 VRPVC => 6 ZLQW\n\
        13 WPTQ , 10 LTCX , 3 RJRHP , 14 XMNCP , 2 MZWV , 1 ZLQW => 1 ZDVW\n\
        5 BMBT => 4 WPTQ\n\
        189 ORE => 9 KTJDG\n\
        1 MZWV , 17 XDBXC , 3 XCVML => 2 XMNCP\n\
        12 VRPVC , 27 CNZTR => 2 XDBXC\n\
        15 KTJDG , 12 BHXH => 5 XCVML\n\
        3 BHXH , 2 VRPVC => 7 MZWV\n\
        121 ORE => 7 VRPVC\n\
        7 XCVML => 6 RJRHP\n\
        5 BHXH , 4 VRPVC => 5 LTCX\n\
";
*/

const string input = "\
        2 KBRD => 3 NSPQ\n\
        1 TMTNM , 5 WMZD => 4 JVBK\n\
        3 TMTNM => 8 JTPF\n\
        3 NDXL => 2 BDQP\n\
        2 VTGNT => 2 TNWR\n\
        1 ZQRBC => 2 WGDN\n\
        2 MJMC => 3 QZCZ\n\
        10 MDXVB , 3 DHTB => 1 SRLP\n\
        1 KBRD , 1 PNPW => 6 SQCB\n\
        1 KDTRS , 4 VTGNT => 7 NDXL\n\
        1 FZSJ => 1 CJPSR\n\
        6 TKMKD => 8 FTND\n\
        2 ZNBSN => 4 DNPT\n\
        16 SKWKQ , 2 FZSJ , 3 GSQL , 1 PNRC , 4 QNKZW , 4 RHZR , 10 MTJF , 1 XHPK => 3 RJQW\n\
        1 NHQW => 8 QNKZW\n\
        16 JZFCN , 9 KWQSC , 1 JGTR => 7 TMTNM\n\
        2 PNRC => 7 LCZD\n\
        1 NLSNC , 14 SXKC , 2 DHTB => 1 ZQRBC\n\
        1 MXGQ , 2 KWQPL => 3 FZSJ\n\
        6 DWKLT , 1 VHNXW , 3 NSPQ => 1 BQXNW\n\
        23 KDTRS => 1 XHPK\n\
        1 PFBF , 3 KBLHZ => 3 MBGWZ\n\
        5 NSPQ => 3 TPJP\n\
        27 SRLP , 12 KWQSC , 14 ZNBSN , 33 HQTPN , 3 HWFQ , 23 QZCZ , 6 ZPDN , 32 RJQW , 3 GDXG => 1 FUEL\n\
        2 NSPQ , 5 ZNBSN , 1 TPJP => 8 PFBF\n\
        1 MSCRZ => 3 ZNBSN\n\
        1 TNWR , 2 ZNBSN => 5 MDXVB\n\
        10 SQCB => 5 MXGQ\n\
        3 JVBK , 1 MTJF , 1 KBLHZ => 2 HQTPN\n\
        2 MJMC => 2 KMLKR\n\
        2 BQXNW , 1 CJPSR , 25 KWQPL => 4 PNRC\n\
        1 VHNXW , 3 KWZKV => 4 TKMKD\n\
        10 VTGNT , 4 JTPF => 9 KWZKV\n\
        168 ORE => 3 JZFCN\n\
        173 ORE => 5 KBRD\n\
        2 TNWR , 1 MBGWZ , 3 NSPQ => 8 SKWKQ\n\
        1 KWZKV , 2 MJMC , 14 SKWKQ => 9 NSTR\n\
        4 JZFCN , 13 PNPW => 2 WMZD\n\
        6 JQNGL => 6 MGFZ\n\
        1 SQCB , 4 NLSNC => 5 DHTB\n\
        5 MGFZ , 39 WGDN , 1 MBGWZ , 2 NSTR , 1 XKBND , 1 SXKC , 1 JVBK => 5 ZPDN\n\
        7 NSPQ , 6 PNPW => 7 NLSNC\n\
        3 TNWR => 9 KWQPL\n\
        9 NLSNC , 4 NDXL , 1 MDXVB => 4 MTJF\n\
        2 VTJC => 7 PNPW\n\
        2 JZFCN => 8 MSCRZ\n\
        134 ORE => 3 JGTR\n\
        3 HQTPN => 4 GSQL\n\
        154 ORE => 9 VTJC\n\
        1 KWQSC , 14 KBRD => 4 JQCZ\n\
        7 PNRC , 1 XKBND => 8 RHZR\n\
        1 JQCZ => 4 VTGNT\n\
        6 BDQP => 6 JQNGL\n\
        7 FTND => 3 XKBND\n\
        2 XHPK , 4 NHQW => 1 MJMC\n\
        1 JQCZ => 5 KDTRS\n\
        1 DNPT => 4 KBLHZ\n\
        1 KMLKR , 26 ZNBSN , 1 LCZD , 11 QNKZW , 2 SQCB , 3 FTND , 24 PNRC => 4 HWFQ\n\
        179 ORE => 6 KWQSC\n\
        2 TKMKD , 3 FZSJ => 2 SXKC\n\
        2 JTPF => 7 VHNXW\n\
        1 FTND => 7 DWKLT\n\
        13 TNWR , 2 QNKZW , 6 SQCB => 5 GDXG\n\
        5 JTPF , 4 ZNBSN , 8 WMZD => 8 NHQW\n\
";


using Chemical = pair<string, int64_t>;
using List = vector<Chemical>;

struct Reaction {
    List from;
    Chemical to;
};

constexpr int64_t TOTAL_ORE = 1000000000000;

struct Factory {
    unordered_map<string, ino64_t> leftovers;
    unordered_map<string, Reaction> reactions;
    int64_t ore_amount = TOTAL_ORE;
};

const string &get_name(const Chemical &c) {
    return c.first;
}

int64_t get_amount(const Chemical &c) {
    return c.second;
}

Chemical read_chemical(istringstream &iss) {
    int amount = 0;
    iss >> amount;

    string chemical;
    iss >> chemical;

    return Chemical(chemical, amount);
}

void read_line(Factory &f, const string &line) {
    enum class State {
        FromChemical,
        ToChemical,
        Separator,
        End
    };

    istringstream iss(line);
    Reaction r;
    State s = State::FromChemical;
    bool stop = false;
    string tmp;

    while(!stop) {
        switch(s) {
        case State::FromChemical:
            r.from.emplace_back(read_chemical(iss));
            s = State::Separator;
            break;
        case State::ToChemical:
            r.to = read_chemical(iss);
            s = State::End;
            break;
        case State::Separator:
            iss >>  tmp;
            if (tmp == ",") {
                s = State::FromChemical;
            } else if (tmp == "=>") {
                s = State::ToChemical;
            } else {
                throw runtime_error("Separator error");
            }
            break;
        case State::End:
            stop = true;
            break;
        }
    }

    auto res = f.reactions.insert({get_name(r.to), r});
    if (!res.second) {
        throw runtime_error("Already inserted");
    }
}

void read_reaction(Factory &f, const string &str) {
    istringstream iss(str);
    while(iss) {
        string line;
        getline(iss, line);
        if (line != "") {
            read_line(f, line);
        }
    }
}

void add_leftover(Factory &f, int64_t amount, const string &chemical) {
    auto search = f.leftovers.find(chemical);
    if (search == f.leftovers.end()) {
        f.leftovers.insert({chemical, amount});
    } else {
        search->second += amount;
    }
}

void do_reaction(Factory &f, int64_t amount, const string &chemical) {
    if (chemical == "ORE") {
        f.ore_amount -= amount;
        return;
    }

    Reaction &r = f.reactions[chemical];

    int64_t num_reactions = amount / get_amount(r.to);
    num_reactions = num_reactions * get_amount(r.to) < amount ? num_reactions + 1 : num_reactions;

    for (auto &c : r.from) {
        for (int64_t i = 0; i < num_reactions; i++) {
            do_reaction(f, get_amount(c), get_name(c));
        }
    }

    add_leftover(f, num_reactions * get_amount(r.to) - amount, chemical);
}

bool process_leftover(Factory &f, int64_t amount, const string &chemical) {
    if (chemical == "ORE") {
        f.ore_amount += amount;
        add_leftover(f, -amount, chemical);
        return false;
    }

    Reaction &r = f.reactions[chemical];

    int64_t num_reactions = amount / get_amount(r.to);

    if (num_reactions == 0) {
        return false;
    }

    add_leftover(f, -(num_reactions * get_amount(r.to)), chemical);

    for (auto &c : r.from) {
        add_leftover(f, get_amount(c) * num_reactions, get_name(c));
    }

    return true;
}

void process_leftovers(Factory &f) {
    bool more_to_process = true;
    while(more_to_process) {
        more_to_process = false;
        for (auto p : f.leftovers) {
            bool res = process_leftover(f, p.second, p.first);
            if (res == true) {
                more_to_process = true;
            }
        }
     }
}

int main() {
    Factory f;
    read_reaction(f, input);

    do_reaction(f, 1, "FUEL");

    cout << "Ore for 1 fuel without recycle: " << (TOTAL_ORE - f.ore_amount) << endl;
    process_leftovers(f);
    int64_t per_fuel = TOTAL_ORE - f.ore_amount;
    cout << "Ore for 1 fuel with recycle: " << per_fuel << endl;

    List leftovers;
    for (auto p : f.leftovers) {
        if (p.second != 0) {
            leftovers.emplace_back(p.first, p.second);\
        }
    }

    int64_t fuel_count = 1;
    while(f.ore_amount >= per_fuel) {
        auto fuel_to_add = (f.ore_amount / per_fuel);
        f.ore_amount %= per_fuel;
        fuel_count += fuel_to_add;

        for (auto l : leftovers) {
            add_leftover(f, get_amount(l) * fuel_to_add, get_name(l));
        }

        process_leftovers(f);

        if (f.ore_amount < 0) {
            throw runtime_error("Hmm");
        }
    }
    cout << fuel_count << endl;
}
