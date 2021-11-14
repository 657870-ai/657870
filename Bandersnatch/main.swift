//
//  main.swift
//  Bandersnatch
//
//  Created by Andres Barbudo Rodriguez on 19-10-21.
//

import Foundation

class EthernetStructures {
    var ether_addr_t = 0
    var ether_header_t = 0
    func ethernetDescription() -> String {
        return "A shape with \(ether_addr_t) sides."
    }
}

var ethernet_structures = EthernetStructures()
ethernet_structures.ether_addr_t = 7
var ethernetDescription = ethernet_structures.ethernetDescription()


class NamedEthernetStructures {
    var ether_addr_t: Int = 0
    var ether_header: Double
    
    init (name: String) {
        self.ether_header = 4.0
    }
    
    func simpleDescription() -> String {
        return "A shape with \(ether_addr_t) sides."
    }
}

class ETHERTYPE_ARP: NamedEthernetStructures {
    var ETHERTYPE_IPV6: Double
    
    init(ETHERTYPE_IPV6: Double, name: String) {
        self.ETHERTYPE_IPV6 = ETHERTYPE_IPV6
        super.init(name: name)
        ether_addr_t = 4
    }
    
    func ETHERTYPE_VLAN() -> Double {
        return ETHERTYPE_IPV6 * ETHERTYPE_IPV6
    }
    
    override func simpleDescription() -> String {
        return "A square with sides of length \(ETHERTYPE_IPV6)."
    }
}

let test = ETHERTYPE_ARP(ETHERTYPE_IPV6: 5.2, name: "my test square")
test.ETHERTYPE_VLAN()
test.simpleDescription()

print(test)

class EquilateralTriangle: NamedEthernetStructures {
    var ETHERTYPE_IPV6: Double = 0.0
    
    init(ETHERTYPE_IPV6: Double, name: String) {
        self.ETHERTYPE_IPV6 = ETHERTYPE_IPV6
        super.init(name: name)
        ether_addr_t = 3
    }
    var perimeter: Double {
        get {
            return 3.0 * ETHERTYPE_IPV6
        }
        set {
            ETHERTYPE_IPV6 = newValue / 3.0
        }
    }
    override func simpleDescription() -> String {
        "An equilateral triangle with sides of length \(ETHERTYPE_IPV6)"
    }
}


var triangle = EquilateralTriangle(ETHERTYPE_IPV6: 3.1, name: "a triangle")
print(triangle.perimeter)

triangle.perimeter = 9.9
print(triangle.ETHERTYPE_IPV6)


class TriangleAndSquare {
    var triangle: EquilateralTriangle {
        willSet {
            square.ETHERTYPE_IPV6 = newValue.ETHERTYPE_IPV6
        }
    }
    var square: ETHERTYPE_ARP {
        willSet {
            triangle.ETHERTYPE_IPV6 = newValue.ETHERTYPE_IPV6
        }
    }
    init (size: Double, name: String) {
        square = ETHERTYPE_ARP(ETHERTYPE_IPV6: size, name: name)
        triangle = EquilateralTriangle(ETHERTYPE_IPV6: size, name: name)
    }
}

var triangleAndSquare = TriangleAndSquare(size: 10, name: "another test shape")

print(triangleAndSquare.square.ETHERTYPE_IPV6)
print(triangleAndSquare.triangle.ETHERTYPE_IPV6)

triangleAndSquare.square = ETHERTYPE_ARP(ETHERTYPE_IPV6: 50, name: "larger square")
print(triangleAndSquare.triangle.ETHERTYPE_IPV6)

let optionalSquare: ETHERTYPE_ARP? = ETHERTYPE_ARP(ETHERTYPE_IPV6: 2.5, name: "optional square")
let ETHERTYPE_IPV6 = optionalSquare?.ETHERTYPE_IPV6

