Pod::Spec.new do |s|
  s.name         = "AliInteractiveLiveCore"
  s.version      = "1.5.0-rc-test"
  s.summary      = "AliInteractiveLiveCore."
  s.description  = <<-DESC
                   It's an SDK for aliyun interactive live core, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyun/alibabacloud-AliIMPInteractiveLive-iOS-SDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "weihe.whq@alibaba-inc.com"}
  s.platform     = :ios
  s.platform     = :ios, "10.0"
  s.source       = { :git => "https://paas-sdk.oss-cn-shanghai.aliyuncs.com/paas/imp/ios/CocoaPods%E5%8F%91%E5%B8%83SDK/1.5.0-rc-test", :tag => "#{s.version}" }
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }	

  # s.dependency 'AliInteractiveRoomLivePusherDependency', '1.0.0.1-SNAPSHOT'

  s.vendored_frameworks = 'AliInteractiveLiveCore.framework'
  s.frameworks = 'Foundation', 'UIKit', 'CoreMotion'
  s.resource_bundles = {'AliInteractiveLiveBeautyResource' => ['AliInteractiveLiveBeautyResource.bundle/AliInteractiveLiveBeautyImageResource.xcassets', 'AliInteractiveLiveBeautyResource.bundle/AliInteractiveLiveBeautyParamResource/*']}
  # s.libraries ='z', 'c++','resolv'
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  s.libraries ='compression', 'c++'
  s.requires_arc = true
   

end