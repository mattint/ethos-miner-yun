require "net/telnet"
require "sinatra"
require "digest"

t = Net::Telnet::new("Host" => "127.0.0.1:6571", "Timeout" => 5, "Prompt" => "yun")
use Rack::Auth::Basic, "ethos-miner-yun" do |u, p|
	if u != "admin"
		return false
	end
	md5 = Digest::MD5.new
	md5 << p
	hp = md5.hexdigest
	md5.reset
	f = open "password.txt"
	r = f.read
	f.close
	md5 << r
	hr = md5.hexdigest
	return hp == hr
end

get "/" do
	erb :main
end

post "/" do
	@cmd = params[:cmd]
	if @cmd != ""
		t.cmd(@cmd)
		erb :congrats
	else
		erb :error
	end
end
