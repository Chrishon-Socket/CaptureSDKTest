//
//  ViewController.swift
//  CaptureSDKTest
//
//  Created by Chrishon Wyllie on 9/26/18.
//  Copyright © 2018 Socket Mobile. All rights reserved.
//

import UIKit
import SKTCapture

class ViewController: UIViewController,
    CaptureHelperDevicePresenceDelegate,
    CaptureHelperErrorDelegate,
    CaptureHelperDevicePowerDelegate,
    CaptureHelperDeviceDecodedDataDelegate,
    CaptureHelperDeviceManagerPresenceDelegate,
    CaptureHelperDeviceManagerDiscoveryDelegate {
    
    var capture = CaptureHelper.sharedInstance
    
    var lastDevice : CaptureHelperDevice?
    
    
    let dateFormatter = DateFormatter()
    let calendar = Calendar.current
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        let appInfo = SKTAppInfo()
        appInfo.developerID = "ef62bc15-59e0-4e86-82a3-493101d7db4e"
        appInfo.bundleID = "SocketMobile.CaptureSDKTest"
        appInfo.appKey = "MCwCFEZvj3UrPIAniunhcucJOx7449j2AhRhBY/I5wnao/txxarXAsdtG3iKsA=="
        
        capture.delegateDispatchQueue = DispatchQueue.main
        capture.pushDelegate(self)
        capture.openWithAppInfo(appInfo, withCompletionHandler: {(result: SKTResult)->(Void) in
            print("opening Capture returned \(result.rawValue)")
            
        })
        
        dateFormatter.dateFormat = "MMddyyyy"
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    
    
    
    
    
    
    func didReceiveError(_ error: SKTResult) {
        // TODO: Add the code to handle the error
        print("Receive an error \(error) from Capture")
    }
    
    func didNotifyArrivalForDevice(_ device: CaptureHelperDevice, withResult result: SKTResult) {
        print("didNotifyArrivalForDevice: \(String(describing: device.deviceInfo.name))")
        
        device.dispatchQueue = DispatchQueue.main
        device.getDecodeActionWithCompletionHandler { (result: SKTResult, decodeAction:SKTCaptureLocalDecodeAction?) in
            print("get decode action returns \(result.rawValue)")
            if result == SKTCaptureErrors.E_NOERROR {
                device.setDecodeAction(decodeAction!, withCompletionHandler: { (result) in
                    
                })
            }
        }
        let deviceManagers = CaptureHelper.sharedInstance.getDeviceManagers()
        deviceManagers[0].getFavoriteDevicesWithCompletionHandler { (result, favoriteDevices) in
            print("getting the favorite devices returns result: \(result.rawValue)")
            if result == SKTCaptureErrors.E_NOERROR {
                if let fav = favoriteDevices {
                    if fav == "*" {
                        deviceManagers[0]
                            .getDeviceUniqueIdentifierFromDeviceGuid(device.deviceInfo.guid!)
                            { (result, deviceIdentifier) in
                                print("getting the device unique identifier returns result: \(result.rawValue)")
                                if result == SKTCaptureErrors.E_NOERROR {
                                    deviceManagers[0].setFavoriteDevices(deviceIdentifier!, withCompletionHandler: { (result) in
                                        print("setting the favorite to \(String(describing: device.deviceInfo.name)) result: \(result.rawValue)")
                                    })
                                }
                        }
                    }
                }
            }
        }
        lastDevice = device
    }
    
    func didNotifyRemovalForDevice(_ device: CaptureHelperDevice, withResult result: SKTResult) {
        print("didNotifyRemovalForDevice: \(String(describing: device.deviceInfo.name))")
        lastDevice = nil
    }
    /// delegate called when a device manager connects to the host
    ///
    /// - Parameters:
    ///   - device: contains the device manager information, such as device type
    ///   - result: contains the result of the device manager connecting to the host
    func didNotifyArrivalForDeviceManager(_ device: CaptureHelperDeviceManager, withResult result: SKTResult) {
        
        device.dispatchQueue = DispatchQueue.main
        device.getFavoriteDevicesWithCompletionHandler { (result, favorites) in
            if result == .E_NOERROR {
                if let fav = favorites {
                    
                }
            }
        }
    }
    
    
    /// delegate called when a device manager disconnects from the host
    ///
    /// - Parameters:
    ///   - device: contains the device manager information, such as device type
    ///   - result: contains the result of the device manager disconnecting from the host
    func didNotifyRemovalForDeviceManager(_ device: CaptureHelperDeviceManager, withResult result: SKTResult) {
        
    }
    
    /// delegate called when a device manager discovered a device
    ///
    /// - Parameters:
    ///   - device: contains the device information, such as device type
    ///   - deviceManager: contains the device manager information from which the discovery was launched
    func didDiscoverDevice(_ device: String, fromDeviceManager deviceManager: CaptureHelperDeviceManager){
        let data  = device.data(using: .utf8)
        let deviceInfo = try! PropertyListSerialization.propertyList(from:data!, options: [], format: nil) as! [String:Any]
        print("device discover: \(deviceInfo)")
        deviceManager.setFavoriteDevices(deviceInfo["identifierUUID"] as! String) { (result) in
            print("setting the favorite devices returns: \(result.rawValue)")
        }
    }
    
    
    /// delegate called when a device manager ended the discovery
    ///
    /// - Parameters:
    ///   - result: contains the result of the device manager disconnecting from the host
    ///   - deviceManager: contains the device manager information from which the discovery ended
    func didEndDiscoveryWithResult(_ result: SKTResult, fromDeviceManager deviceManager: CaptureHelperDeviceManager){
        print("end discovery with result: \(result.rawValue)")
    }
    
    var map: [String: String] = [:] // data type : data
    
    func didReceiveDecodedData(_ decodedData: SKTCaptureDecodedData?, fromDevice device: CaptureHelperDevice, withResult result: SKTResult) {
        if result == SKTCaptureErrors.E_NOERROR {
            
            print("decoded data: \(decodedData!.stringFromDecodedData()!)")
            
            if let data = decodedData?.stringFromDecodedData() {
                
                let words = data.components(separatedBy: "\n")
                
                for word in words {
                    print("word: \(word)")
                    let offset: Int = 3
                    
                    guard word.count > offset else { continue }
                    
                    let upperIndex = word.index(word.startIndex, offsetBy: offset - 1)
                    
                    let dataType = String(word[...upperIndex])
                    
                    let lowerIndex = word.index(word.startIndex, offsetBy: offset)
                    let dataFromWord = String(word[lowerIndex...])
                    
                    map[dataType] = dataFromWord
                    
                    print("\(dataType) - \(dataFromWord)")
                }
                
                guard let dob = map["DBB"] else { return }
                let oldEnough: Bool = isOldEnoughToEnter(dob: dob)
                
                guard let expiryDate = map["DBA"] else { return }
                let validCard: Bool = hasAValidIDCard(date: expiryDate)
                
                print(oldEnough, validCard)
            }
            
            //            self.lastDevice?.setDataConfirmationWithLed(.green, withBeep: .none, withRumble: .good, withCompletionHandler: { (result: SKTResult) in
            //                print("confirming decoded data returned \(result.rawValue)")
            //            })
        }
    }
    
    private func isOldEnoughToEnter(dob: String) -> Bool {
        
        guard let dateOfBirth = dateFormatter.date(from: dob) else { return false }
        
        let currentDate = Date()
        
        let timeSince = currentDate.timeIntervalSince(dateOfBirth)
        
        print("time since: \(timeSince)")
        
        let components = calendar.dateComponents([.month, .year], from: dateOfBirth, to: currentDate)
        
        guard
            let years = components.year,
            let months = components.month
            else { return false }
        
        print("It's been \(String(describing: years)) year(s) and \(String(describing: months)) months")
        
        return years >= 21
    }
    
    private func hasAValidIDCard(date: String) -> Bool {
        guard let expiryDate = dateFormatter.date(from: date) else { return false }
        let currentDate = Date()
        return expiryDate > currentDate
    }
    
    func didChangePowerState(_ powerState: SKTCapturePowerState, forDevice device: CaptureHelperDevice){
        switch powerState {
        case .onAc:
            print("scanner on AC")
            break
        case .onBattery:
            print("scanner on Battery")
            break
        case .onCradle:
            print("scanner on craddle")
            break
        case .unknown:
            print("unknown scanner power state")
            break
        }
    }
    
    
    func didChangeBatteryLevel(_ batteryLevel: Int, forDevice device: CaptureHelperDevice){
        print("new battery level: \(SKTHelper.getCurrentLevel(fromBatteryLevel: Int(batteryLevel)))%")
    }
    
    
}

//class ViewController: UIViewController {
//
//    var capture = CaptureHelper.sharedInstance
//
//    private final let developerID: String = "da08ec19-5519-429b-b561-9edb817327e2"
//    private final let bundleID: String = "SocketMobile.CaptureSDKTest"
//    private final let appKey: String = "MCwCFEZvj3UrPIAniunhcucJOx7449j2AhRhBY/I5wnao/txxarXAsdtG3iKsA=="
//
//    private var map: [String: String] = [:]
//
//    override func viewDidLoad() {
//        super.viewDidLoad()
//        // Do any additional setup after loading the view, typically from a nib.
//
//        let appInfo = SKTAppInfo()
//        appInfo.developerID = developerID
//        appInfo.bundleID = bundleID
//        appInfo.appKey = appKey
//
//        capture.delegateDispatchQueue = DispatchQueue.main
//        capture.pushDelegate(self)
//        capture.openWithAppInfo(appInfo) { (result) in
//            print("opening Capture returned \(result.rawValue)")
//        }
//    }
//
//
//}
//
//
//extension ViewController: CaptureHelperDelegate {
//
//}
//
//extension ViewController: CaptureHelperDeviceManagerPresenceDelegate {
//
//    func didNotifyArrivalForDeviceManager(_ device: CaptureHelperDeviceManager, withResult result: SKTResult) {
//        print("device manager has arrived")
//    }
//
//    func didNotifyRemovalForDeviceManager(_ device: CaptureHelperDeviceManager, withResult result: SKTResult) {
//        print("device manager removed")
//    }
//}
//
//
//extension ViewController: CaptureHelperDevicePresenceDelegate {
//
//    func didNotifyArrivalForDevice(_ device: CaptureHelperDevice, withResult result: SKTResult) {
//        print("scanner arrived")
//    }
//
//    func didNotifyRemovalForDevice(_ device: CaptureHelperDevice, withResult result: SKTResult) {
//        print("scanner removed")
//    }
//}
//
//
//extension ViewController: CaptureHelperDeviceDecodedDataDelegate {
//
//    func didReceiveDecodedData(_ decodedData: SKTCaptureDecodedData?, fromDevice device: CaptureHelperDevice, withResult result: SKTResult) {
//        if result == SKTCaptureErrors.E_NOERROR {
//            print("decoded data: \(decodedData!.stringFromDecodedData()!)")
//
//            if let data = decodedData?.stringFromDecodedData() {
//
//                let words = data.components(separatedBy: "\n")
//
//                for word in words {
//                    print("word: \(word)")
//                    let offset: Int = 3
//
//                    guard word.count > offset else { continue }
//
//                    let upperIndex = word.index(word.startIndex, offsetBy: offset - 1)
//
//                    let dataType = String(word[...upperIndex])
//
//                    let lowerIndex = word.index(word.startIndex, offsetBy: offset)
//                    let dataFromWord = String(word[lowerIndex...])
//
//                    map[dataType] = dataFromWord
//
//                    print("\(dataType) - \(dataFromWord)")
//                }
//
//                guard let dob = map["DBB"] else { return }
//                _ = isOldEnoughToEnter(dob: dob)
//            }
//        }
//    }
//
//    private func isOldEnoughToEnter(dob: String) -> Bool {
//        let formatter = DateFormatter()
//        formatter.dateFormat = "MMddyyyy"
//
//        guard let dateOfBirth = formatter.date(from: dob) else { return false }
//
//        let currentDate = Date()
//
//        let timeSince = currentDate.timeIntervalSince(dateOfBirth)
//
//        print("time since: \(timeSince)")
//
//
//        let calendar = Calendar.current
//
//        let components = calendar.dateComponents([.month, .year], from: dateOfBirth, to: currentDate)
//
//        guard
//            let years = components.year,
//            let months = components.month
//            else { return false }
//        //let days = components.day
//        print("It's been \(String(describing: years)) year(s) and \(String(describing: months)) months")
//
//        return years >= 21
//    }
//
//    private func hasAValidIDCard(expiryDate: String) -> Bool {
//        return true
//    }
//
//}
