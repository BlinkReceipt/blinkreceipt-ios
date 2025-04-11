Pod::Spec.new do |s|

  s.name         = "BlinkReceipt"
  s.version      = "1.57.0"
  s.summary      = "BlinkReceipt SDK"

  s.description  = <<-DESC
This is the BlinkReceipt SDK
                   DESC

  s.homepage     = "https://github.com/BlinkReceipt/blinkreceipt-ios"
  s.license      = { :type => "MIT", :file => "LICENSE" }


  s.author             = { "Darren Bassman" => "darren.bassman@microblink.com" }
  s.platform     = :ios
  s.ios.deployment_target = "13.0"
  
  s.source       = { :git => "https://github.com/BlinkReceipt/blinkreceipt-ios.git", :tag => "#{s.version}" }

  s.vendored_frameworks = ["BlinkReceipt.xcframework"]
  
  s.user_target_xcconfig = { 'BLINKRECEIPT_VERSION' => s.version }

end
