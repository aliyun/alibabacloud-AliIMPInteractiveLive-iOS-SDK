Pod::Spec.new do |s|
  s.name         = "AliInteractiveDocumentCore"
  s.version      = "1.4.1.20211123006"
  s.summary      = "AliInteractiveDocumentCore."
  s.description  = <<-DESC
                   It's an SDK for aliyun interactive document core, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyun/alibabacloud-AliIMPInteractiveLive-iOS-SDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "weihe.whq@alibaba-inc.com"}
  s.platform     = :ios
  s.platform     = :ios, "10.0"
  s.source       = { :git => "https://github.com/aliyun/alibabacloud-AliIMPInteractiveLive-iOS-SDK.git", :tag => "#{s.version}" }
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }	

  s.vendored_frameworks = 'AliInteractiveDocumentCore.framework'
  s.frameworks = 'Foundation', 'UIKit'
  s.libraries ='resolv'
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  #s.libraries = 'z'  
  s.requires_arc = true
   

end