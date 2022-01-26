//
// Created by Andres Barbudo Rodriguez on 25-01-22.
//

import Foundation
func vDSP_mmulD(_ __A: UnsafePointer<Double>,
                _ __IA: vDSP_Stride,
                _ __B: UnsafePointer<Double>,
                _ __IB: vDSP_Stride,
                _ __C: UnsafeMutablePointer<Double>,
                _ __IC: UnsafeMutablePointer<Double>,
                _ __IC: vDSP_Stride,
                _ __M: vDSP_Length,
                _ __N: vDSP_Length,
                _ __P: vDSP_Length)